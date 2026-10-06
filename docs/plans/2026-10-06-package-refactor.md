# 方案：清理过时脚本、打包核心代码并统一工程规范

## v1

### 目标与范围

把仓库整理为结构清晰的开源项目，**不改变任何实验结果**：

1. 删除当前流程不再使用的旧脚本与历史产物（迁入数据仓库保存来源，不丢失）。
2. 把核心实现收拢为 `cllmark/` 包，统一模块命名、公开接口、文档字符串与类型注解。
3. 用 `pyproject.toml` 统一项目元数据、依赖与 ruff 规范；全仓库 lint + format；增加 CI。
4. 用安全的命令行（`python -m cllmark`）替代旧脚本里写死路径、会删改语料的批量 `__main__`。
5. 同步更新文档、Makefile、AGENTS.md 与代理配置。

属于**工程改动**：规则语义、度量定义、语料、随机协议均不变。由于 `benchmarks/engine.py`、`common.py` 等属于协议摘要，改动后运行与此前不可比，需逐单元证明结果相同并建立新参考（由主会话决定）。

### 现状与证据

- 当前流程只使用：`rule_engine.py`、`change_program_style.py`、`watermark_core.py`、`code_io.py`、`bch_utils.py`、`rule_dict_bit_acc.py`、`styleList.json`、三个目录适配器（`folder_transform_check.py`、`watermark_bit.py`、`watermark_extract.py`，被 `benchmarks/engine.py:53-58` 按模块名导入）及 `python|c|cpp|javascript/rules.py`。
- 以下根目录文件不被核心、benchmarks、tools、tests 导入（`git grep` 已确认），属语料生成或论文旧实验的一次性脚本/产物：`benchmark_passrate.py`、`build_so.py`、`calu.py`、`code_transform_provider.py`、`error_check.py`、`extract.py`、`extract_func.py`、`folder_to_jsonl.py`、`fortowhile.py`、`openai_ml.py`、`short_code_filter.py`、`test.py`、`transform_list_comprehensions.py`；`generations(2).json`、`output_json.jsonl`、`output_json.jsonl_passatk.json`、`output_json.jsonl_results.jsonl`、`support_transform.json`；`test/`、`test_1/`；`requirements.txt`（旧环境记录，已由 `benchmarks/requirements.lock` 取代）；`.env.example`（仅服务 `openai_ml.py`）。
- `benchmarks/engine.py:41-45` 的 `reset_legacy_state` 只重载名为 `<language>.transform*` 的模块，阶段 B 后已不存在，属死代码（规则无状态由 `tests/test_rule_engine.py::test_rules_have_no_state_between_files` 保证）。
- 引擎依赖两处模块属性替换：`module.SCTS = self.parser`（三个适配器）与 `self.bch.decode = decode`（记录原始码字）。

### 目标结构

```
cllmark/
  __init__.py        # __version__ 与公开 API：SCTS, analyze, embed, extract, LANGUAGES
  __main__.py        # from .cli import main; main()
  cli.py             # argparse：analyze / embed / extract 子命令
  bch.py             # ← bch_utils.py
  source_io.py       # ← code_io.py
  transform.py       # ← change_program_style.py（类名 SCTS 保留）
  watermark.py       # ← watermark_core.py
  directories.py     # ← folder_transform_check.py + watermark_bit.py + watermark_extract.py
  rules/
    __init__.py
    engine.py        # ← rule_engine.py
    pairs.py         # ← rule_dict_bit_acc.py（变量名 rule_dict 改为 WATERMARK_PAIRS）
    styles.json      # ← styleList.json
    python.py c.py cpp.py javascript.py   # ← */rules.py
benchmarks/ tools/ tests/ docs/ corpus/   # 保留
pyproject.toml  Makefile  README.md  AGENTS.md  .github/workflows/ci.yml
```

全部移动用 `git mv`（保留历史），先移动再改内容。

### 步骤

**步骤 0：等价性快照（任何改动之前）。** 在 scratch 写 `/tmp/claude-0/-home-user-CLLMark-legacy/80b9c75d-2ecb-5ef2-b267-4168de6c4042/scratchpad/equivalence.py`（不入库），通过 `--layout old|new` 选择导入名（old：`change_program_style`、`watermark_core`、`rule_dict_bit_acc`；new：`cllmark.transform`、`cllmark.watermark`、`cllmark.rules.pairs`），输出 JSON：
- 规则层：对 `benchmarks/config.json` 全部组的去重源文件（按语言），对 `styles.json` 中该语言的每个样式，记录 `sha256(change_file_style(style, code))` 与 `success`，异常记为异常类型名；
- 流程层：对每个函数级单元（文件）与项目级单元（目录），`analyze` 结果、`embed(watermark=[1,0,1,0])` 输出各文件 sha256、对嵌入结果 `extract` 的二元组；`random.seed(20261005)` 在每个单元前重置。
多进程（4 个）。先在旧布局下生成 `equiv_before.json`。之后每个步骤结束都生成 `equiv_after_<步骤>.json` 并与之**完全相同**（逐键比较，报告不同项数）。

**步骤 1：删除过时文件。** 删除上节列出的全部文件与目录，以及 `.gitignore` 中只为它们存在的条目（如 `code_snippets.rar`；保留通用条目）。先把它们原样复制到数据仓库检出 `/home/user/cllmark-legacy-data` 的 `provenance/legacy-scripts/`（脚本）与 `provenance/legacy-results/`（json/jsonl 与 test、test_1），加 `provenance/README.md` 说明来源提交 `c2a0a16f` 及各文件原用途（一行一个，用途取自 `docs/CODE_MAP.md`）。数据仓库只提交，不推送（由主会话推送）。`docs/plans/2026-10-06-phase-c-gate.while_to_for_audit.py` 属历史方案附件，保留不动。

**步骤 2：建包与移动。**
- 按目标结构 `git mv`；删除空的 `python/ c/ cpp/ javascript/` 目录。
- 包内导入一律相对导入（`from .rules.engine import Grammar`）。`transform.load_rules` 改为 `importlib.import_module(f'cllmark.rules.{language}')`；`cpp.py` 从 `.c` 导入。
- `transform.library_path`：保持查找顺序不变——先 `Path('build') / ...`（相对当前工作目录，冻结运行依赖），再 `REPOSITORY / '.benchmark-cache' / 'toolchain' / ...`，其中 `REPOSITORY = Path(__file__).resolve().parents[1]`。
- `styles.json` 的读取位置改为 `Path(__file__).parent / 'rules' / 'styles.json'`（所有读取方统一用 `cllmark.rules.STYLES_PATH` 常量）。
- `directories.py` 合并三个适配器，公开函数：`load_project(directory, names=None)`、`analyze_directory(directory, language, transformer=None) -> int`（写 `support_transform.json`，返回“无可用规则对的文件数”——与旧 `check_support_transform` 返回值相同，先核对旧实现的确切返回值并保持一致）、`embed_directory(directory, language, bits, transformer=None)`、`extract_directory(directory, language, bits, transformer=None) -> tuple[bool, bool]`。`transformer` 为 None 时构造 `SCTS(language)`。删除 `see_tree`、`display_diff_in_console`、`get_subfolder`、`read_json`（内联为 `json.loads(path.read_text(...))`）、所有 `__main__` 与 `tqdm`、`print`。
- `watermark.py` 必须通过模块属性调用 `bch.encode_bch_7_4` / `bch.decode`（`from . import bch`），**不得** `from .bch import decode`，否则引擎的码字记录失效。随机数调用次序与次数不变。
- `benchmarks/engine.py`：导入 `cllmark.transform`、`cllmark.directories`、`cllmark.bch`、`cllmark.rules.pairs`；用 `transformer=self.parser(language)` 传参取代模块属性替换 `module.SCTS = ...`；`read_file_with_auto_encoding` 改用 `cllmark.source_io.read_source`；删除死代码 `reset_legacy_state` 及其调用；保留 `self.bch.decode` 替换（指向 `cllmark.bch` 模块）。其余逻辑不动。
- `benchmarks/common.py::source_paths`：纳入 `cllmark/**/*.py`、`cllmark/rules/styles.json`、`pyproject.toml`，移除根目录 `*.py` 通配与 `styleList.json`；`common.py:238` 等复制 `styleList.json` 处改为复制整个 `cllmark/` 包所需文件（核对调用方语义后最小改动）。冻结副本里 `source/` 作为工作目录与 `sys.path` 根，确认 `import cllmark` 在冻结副本中可用。
- tools、tests：改为从 `cllmark` 导入；删除 `sys.path.insert` 之外不必要的路径操作（tools 仍需把仓库根加入 `sys.path`，统一写成一个 `_repository.py` 小模块或保持每个脚本一行，二选一：**保持每个脚本顶部一行 `sys.path.insert(0, str(REPOSITORY))`**）。
- 跑 `python -m unittest discover -s tests`、步骤 0 等价性比较。

**步骤 3：规范与质量。**
- `pyproject.toml`：`[project]`（name `cllmark`，version `0.1.0`，description，`requires-python = ">=3.11"`，dependencies 与 `benchmarks/requirements.lock` 中核心运行所需一致：`tree-sitter==0.20.2`、`chardet` 版本照锁文件），`[project.scripts] cllmark = "cllmark.cli:main"`，`[tool.setuptools.packages.find] include = ["cllmark*"]`，`[tool.setuptools.package-data] cllmark = ["rules/styles.json"]`；`[tool.ruff]` line-length 120、target py311，lint 选择 `E,F,W,I,B,UP,SIM,RUF`，按需忽略与本库风格冲突且不影响正确性的个别规则（在配置中逐条注释原因）。不加入 license 字段（许可证由用户决定）。
- 用 `.venv-benchmark` 安装 ruff（固定版本写入 `benchmarks/requirements.lock` 的 dev 段或 `pyproject` 的 `[project.optional-dependencies] dev`），对 `cllmark/ benchmarks/ tools/ tests/` 运行 `ruff check --fix` 与 `ruff format`；剩余告警逐条修复（不得用 `noqa` 掩盖真实问题）。
- `cllmark/` 内公开函数与类补全类型注解与一行以上文档字符串；模块顶部文档字符串说明职责。规则模块（`rules/*.py`）只做 lint/format，不改写逻辑。
- `cli.py`：`cllmark analyze DIR --language L`、`cllmark embed DIR --language L --bits 1010`、`cllmark extract DIR --language L --bits 1010`；`embed` 默认写入 `--output OUT`（复制目录后在副本上嵌入），只有显式 `--in-place` 才修改原目录。退出码：extract 匹配为 0、不匹配为 1。为 CLI 增加测试（临时目录、Python 小项目）。
- 依赖 JavaScript 固定环境的测试在环境缺失时 `skipUnless`（参照 `HAS_GRAMMARS` 写法），不报错。
- 每次修改后跑测试与等价性比较。

**步骤 4：CI 与命令入口。**
- `.github/workflows/ci.yml`：ubuntu-latest、Python 3.11；步骤：checkout（不拉子模块）、`make setup-benchmark`、`.venv-benchmark/bin/ruff check . && ruff format --check .`、`make test`。不需要语料与 JavaScript 环境的测试必须在 CI 中通过，其余 skip。
- Makefile：新增 `lint`（ruff check + format --check）、`format`；`test` 不变；`.PHONY` 更新。

**步骤 5：文档。**
- README：项目简介、目录结构（新布局）、快速开始（`make corpus`、`make setup-benchmark`、`python -m cllmark ...`、`make smoke/benchmark`）、开发规范（`make lint/format/test`）、文档索引；删除对已删脚本的描述，指向数据仓库 `provenance/`。
- `docs/CODE_MAP.md` 按新结构重写模块表；删除已删脚本的行；“`corpus/data/` 实验快照”一节保留但说明根目录对应脚本已迁到数据仓库 `provenance/`。
- `docs/RULES.md`、`docs/RESEARCH_LOOP.md`、`docs/PAPER_ALIGNMENT.md`、`benchmarks/baselines/README.md`：更新路径与文件名（`styleList.json`→`cllmark/rules/styles.json`，`rule_engine.py`→`cllmark/rules/engine.py` 等）。`docs/experiments/`、`docs/plans/` 中的历史记录不改写。
- `AGENTS.md`：路径更新；“不直接运行旧脚本中的批量 `__main__`”改为“目录级操作使用 `python -m cllmark`（默认不改原目录）”。`.claude/agents/*.md`、`.claude/skills/plan-delegate/SKILL.md` 同步。
- `python3 tools/build_code_index.py` 重建索引并 `--check` 通过。

### 验收标准

- 每个步骤后：`equiv_after_*.json` 与 `equiv_before.json` 0 差异；`.venv-benchmark/bin/python -m unittest discover -s tests` 全部通过（JavaScript 环境相关测试在本容器应能运行，ws 外）；最终 `ruff check .` 与 `ruff format --check .` 无告警；`make doctor`、`make inventory`（25 组、10,810 单元）正常。
- `git grep` 不再出现已删除模块名（`change_program_style`、`watermark_core`、`rule_dict_bit_acc`、`code_io`、`bch_utils`、`folder_transform_check`、`watermark_bit`、`watermark_extract`、`rule_engine`、`styleList`）——`docs/experiments/`、`docs/plans/` 历史记录除外。
- 回报：每步的 diff stat、测试数、等价性差异数、ruff 告警数、遗留问题。

### 禁止事项

- 不改变任何规则、度量、配置中的协议字段、随机次序、输出格式（`support_transform.json` 文件名与内容格式不变）。
- 不修改 `benchmarks/baselines/`、`corpus/` 语料（只在数据仓库新增 `provenance/`）。
- 不删除或跳过可在本环境运行的测试；不用 `noqa`/忽略规则掩盖真实缺陷。
- 不提交主仓库（主会话审查后提交）；不推送数据仓库。

**步骤 6：性能（用户新增要求，在步骤 1–5 完成后进行）。**
- 先测量，后优化。写 scratch 脚本 `profile.py`（不入库），在新布局上对每种语言各取 200 个函数级单元与 20 个项目级单元（固定种子抽样），分别用 `cProfile` 剖析 `analyze`、`embed`、`extract`，以及 `tools/rule_audit.py` 单语言全量；输出各阶段总耗时、按函数累计耗时前 25 项到 `profile_before.txt`。
- 另从最近一次全量运行的逐单元结果统计墙钟构成：分析/嵌入/提取/功能测试/攻击/性质探针各占比（runner 的 rows 里已有耗时字段），写入 `wallclock.txt`。
- 回报这两份数字后**停下**，由主会话根据热点决定优化项（写入本方案 v2），不要先行优化。

## v2：执行记录

按用户要求由主会话直接实施（未派子代理）；步骤 1–5 与计划一致，以下为偏离与追加：

- **等价性验证**：快照必须固定 `PYTHONHASHSEED`（与评估循环相同的 20261005）。部分 C/C++ 规则沿用原实现的 `list(集合)[0]`，未固定种子时同一代码两次运行结果不同（`corpus/dataset/CodeNet_H/CN435.c` 的 7.8 即为一例）。固定种子后，重构（提交 `8c06557d`）与 `c2a0a16f` 在 28,898 个文件 × 全部样式及 10,810 个单元上 39,708/39,708 项完全相同。
- **ruff 不安全修复的缺陷**：`SIM103` 的自动修复把 `cllmark/rules/cpp.py::stream_head` 的循环改成首轮即返回，被 `GoldenRewriteTests`（cpp 9.2）发现；已恢复原逻辑，并逐个函数审查了其余不安全修复（列表拼接改解包、布尔返回化简等，均等价）。`RUF015`（`list(x)[0]` → `next(iter(x))`）未采用：空输入时异常类型不同。
- **步骤 6 性能**（`28827e01`）：在固定 292 个单元样本上剖析，热点为 chardet（约 42%）、`apply_edits` 的两两冲突检查（4,300 万次比较）与 `apply` 中无变化时的去空白比较。冲突检查改为有序索引（重叠时回退两两比较；保留原实现 `offset + 2*i` 的同位插入次序，随机测试与 20,000 组随机编辑同 `c2a0a16f` 完全一致）。
- **用户追加：去除 chardet，语料预先规范化**（`dc96878e`，数据仓库 `9bc0ab3b`）：全部 57,347 个源文件本已是合法 UTF-8；8,554 个 CRLF 文件改为 LF，固定上游提交的 JavaScript 副本保持原字节。chardet 曾把 5 个 UTF-8 文件（7 个组内副本）误判为 Windows-1252/1254 并读成乱码；改为严格 UTF-8 后快照仅这 5 个文件与包含它们的 4 个单元不同。这改变了方法输入，属于方法协议改动，需建立新参考。
- **性能结果**：同一样本 198.2 s → 46.7 s（4.2×）；嵌入 61.0 → 1.9 s，性质探针 80.2 → 33.3 s，分析 16.5 → 5.7 s。剩余时间主要是 tree-sitter 解析与查询（C 实现）及规则守卫本身。
- **评估环境限制**：本容器无 IPv6，`ws` 仓库自带测试挂起，11 个 ws 单元在 180 s 单元期限内超时（框架错误）。这是环境问题，不是代码问题；需要在有 IPv6 的环境中复跑这 11 个单元。
