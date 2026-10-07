# CLLMark — 旧版论文实现

本仓库是 CLLMark 旧版方法的实现：通过可逆的语义保持变换（RSPT）对 Python、C、C++ 和 JavaScript 代码做后处理，嵌入并检测多比特水印，使用 BCH(7,4,1) 编码与纠错；并附带可复现的全量评估循环。

规则层是声明式引擎：每条规则由 tree-sitter 查询模式、具名守卫和锚定到节点的原子编辑组成，水印流程在内存中完成（每个文件读一次、写一次）。在原有规则对之外新增了语义保持规则（Python 25 对、C 21 对、C++ 22 对、JavaScript 25 对），并修正了原有规则中会改变程序行为的情形（包括 CodeNet 评估暴露的位置缺陷，见 [规则修复方案](docs/plans/2026-10-07-rule-fixes.md)）。详见 [规则引擎与规则目录](docs/RULES.md) 与 [实验记录](docs/experiments/2026-10-rule-engine.md)。

**版本定位：当前代码对应旧版论文《Detecting and Tracing LLM Code via Reversible Watermarking》。新版 TOSEM 草稿《CLLMark: Traceability-Enabled Watermarking for LLM-Generated Code》作为后续对照，尚不能据此认定本仓库已完整实现新版方法。** 代码与旧版论文之间的实现差异见 [论文对照](docs/PAPER_ALIGNMENT.md)。

## 目录结构

```text
.
├── cllmark/                    # 核心包
│   ├── watermark.py            #   内存中的分析、嵌入、提取（槽位顺序、比特到规则的映射）
│   ├── transform.py            #   StyleTransformer：样式编号 → 规则，语法检查
│   ├── directories.py          #   目录级分析/嵌入/提取（support_transform.json）
│   ├── cli.py                  #   python -m cllmark {analyze,embed,extract}
│   ├── bch.py                  #   BCH(7,4,1) 编码与单比特纠错
│   ├── source_io.py            #   UTF-8 读写（universal newlines），每个文件读一次、写一次
│   ├── nodes.py                #   节点粒度位点（sites/slots）与按位点改写
│   ├── robust/                 #   阶段 2：带密钥的鲁棒水印（keys、anchors、embed、detect、stable_pairs）
│   └── rules/
│       ├── engine.py           #   规则表示、单次查询匹配、原子编辑与冲突处理、解析缓存
│       ├── python.py c.py cpp.py javascript.py   # 各语言规则（RULES：样式编号 → Rule）
│       ├── pairs.py            #   水印规则对（顺序即槽位顺序）
│       └── styles.json         #   样式目录
├── benchmarks/                 # 评估协议：冻结运行、真实功能测试、指标、门禁与基线
├── tools/                      # 环境初始化、科研循环 CLI、规则审计、语料工具、代码索引
├── tests/                      # 单元与流程测试
├── docs/                       # 代码地图、规则目录、科研循环、CodeNet、论文对照、实验记录与方案
├── external/                   # 被忽略：导入的外部数据集（make codenet-setup 生成 external/codenet/）
├── corpus/                     # 语料子模块（私有仓库 Noelle1831-k/CLLMark-legacy-data）
├── pyproject.toml              # 包元数据、依赖与 ruff 规范
└── Makefile                    # 日常命令入口
```

原实现中用于生成语料和旧实验的一次性脚本（`extract*.py`、`openai_ml.py`、`benchmark_passrate.py` 等）及其历史结果已移到数据仓库的 `provenance/`，不再属于本项目代码。

## 快速开始

需要 Python 3.11、C++ 编译器；JavaScript 评估另需 Node.js、npm 与 pnpm。

```bash
make corpus            # 拉取语料子模块（需要私有数据仓库的读取权限）
make setup-benchmark   # 独立环境 .venv-benchmark + 固定提交的 tree-sitter 语法库
make setup-javascript  # 可选：JavaScript 项目、仓库与 Exercism 的固定检出和依赖
make doctor            # 检查固定依赖、解析库与规则导入
```

在代码中使用（项目为 `{文件名: 源码}` 的映射）：

```python
from cllmark import StyleTransformer, analyze, embed, extract

transformer = StyleTransformer("python")
support = analyze(transformer, "python", files)
marked = {**files, **embed(transformer, "python", files, support, [1, 0, 1, 0])}
message_matches, codeword_matches = extract(transformer, "python", marked, support, [1, 0, 1, 0])
```

命令行（输入目录不会被修改；`embed` 把带水印的副本写到新目录）：

```bash
.venv-benchmark/bin/python -m cllmark analyze path/to/project --language python
.venv-benchmark/bin/python -m cllmark embed path/to/project -l python -b 1010 -o marked/
.venv-benchmark/bin/python -m cllmark extract marked/ -l python -b 1010   # 退出码 0 表示匹配
```

当前提取协议是“预期消息匹配”：需要嵌入时保存的 `support_transform.json` 和待验证的消息，不等同于新版论文的独立提取。

## 科研循环

```bash
make smoke       # 流程测试 + 每组 2 个实验单元（只验证运行框架）
make benchmark   # 代码改动后：更新索引、测试、冻结源码与输入、全量运行、对照固定基线
```

默认全量为 25 组、10,810 个实验单元（含 JavaScript 6 组）。每次运行在冻结副本中执行，保留容量不足和失败样本，并校验源码与原始输入没有被更改。Python/C++/JavaScript MBXP 与 Exercism 使用本地真实功能测试，JavaScript 仓库使用其自带测试套件；默认语料中的 CodeNet 组与拆分项目缺少功能 oracle，结果记录为 N/A（有用例的 CodeNet 数据集见下一节）。配置、指标分母、门禁与续跑见 [科研循环文档](docs/RESEARCH_LOOP.md)。

修改规则或嵌入/提取算法后，还要在固定提交的 10 万行级真实仓库上验证功能保持：

```bash
make repo-setup     # 首次
make repo-instant   # 约 11 秒
make repo-check     # 约 7 分钟：逐仓库嵌入水印并逐条规则全仓改写，运行仓库自带测试
```

## CodeNet 生成/手写数据集评估

在 [Noelle1831-k/dataset](https://github.com/Noelle1831-k/dataset)（固定提交 `8f5f30e8`）上评估：`generated/` 为大模型生成代码（嵌入、提取、攻击、功能保持），`solutions/*/ref.*` 为手写标准答案（**不嵌入**，只检测未加水印的手写代码是否天然读出水印而误报）。功能 oracle 是每题约 11 条 stdin/stdout 用例，全量应在 Linux x86_64 + GCC 上运行。

```bash
make codenet-setup [SOURCE=已有检出]          # 导入到被忽略的 external/codenet/（不写 corpus/）
.venv-benchmark/bin/python tools/research_loop.py run --config benchmarks/config-codenet.json   # 另有 -extended/-node/-node-extended
.venv-benchmark/bin/python tools/codenet_report.py RUN_DIR [RUN_DIR ...] --output docs/experiments/NAME.md
```

要点（规则修复后，标签 `codenet-eval-2`）：生成代码功能回退 0、嵌入后检出率 99.8–100%；对固定消息 `1010` 的手写代码误报 0–5%，但换一个消息可高达 13–96%（JavaScript 手写代码 84–96% 读出 `0000`）——预期消息匹配的误报率依赖消息选择。协议、导入与 oracle 见 [CODENET.md](docs/CODENET.md)，结果见 [首轮](docs/experiments/2026-10-07-codenet.md) 与 [规则修复后](docs/experiments/2026-10-07-codenet-v2.md) 的实验记录。

## 鲁棒带密钥水印（阶段 2，实验性）

`cllmark/robust/` 用全部可改写位点承载由密钥决定的比特：位点按位置无关的锚点（`tok`：标识符与字面量；`struct`：结构骨架）寻址，比特经 HMAC 白化，检测只需密钥和待检代码（不需要支持文件），按二项检验给出可校准的 p 值。两个方案：`s1` 重复嵌入消息位并以 HMAC 标签判定，`s2` 全部位点放消息相关的密钥序列；消息 4 或 8 位。只使用在默认语料上标定为稳定的规则对（`cllmark/robust/stable_pairs.py`）。

```python
from cllmark.robust import Scheme, derive_key, embed, detect

result = embed(transformer, "python", files, Scheme("s2", 4, "struct"), key, [1, 0, 1, 1])
found = detect(transformer, "python", {**files, **result.written}, Scheme("s2", 4, "struct"), key, None)  # 盲提取
```

评估使用 10 份 `benchmarks/config-rw-*.json`（两个方案 × 4/8 位 × 两种锚点，加 BCH 文件/节点粒度基线），在 CodeNet 生成/手写组、多文件项目与 14 个 JavaScript 仓库上测检出率、全部消息上的误报率、跨消息误接受、13 种攻击与功能保持，报告由 `tools/robust_report.py` 生成。设计、用法与限制见 [ROBUST_WATERMARK.md](docs/ROBUST_WATERMARK.md)。

## 开发

```bash
make setup-dev   # 安装固定版本的 ruff
make lint        # ruff check + format --check
make format      # 自动修复与格式化
make test        # 单元与流程测试（缺少语料或 JavaScript 环境的测试自动跳过）
make perf        # 性能基准：启动、各阶段耗时与峰值内存（见 docs/PERFORMANCE.md）
make code-map    # 重建 docs/code-index.json
```

CI（`.github/workflows/ci.yml`）在每次推送和 PR 上运行 lint 与测试。修改规则、度量或评估协议后需按 [AGENTS.md](AGENTS.md) 运行全量 benchmark；新增规则的审计流程见 [RULES.md](docs/RULES.md#新增或修改规则的流程)。

## 文档

- [代码地图](docs/CODE_MAP.md)：模块职责、调用关系与数据流。
- [规则引擎与规则目录](docs/RULES.md)：规则表示、约束执行、各语言规则及其等价性依据。
- [科研循环与全量 benchmark](docs/RESEARCH_LOOP.md)：固定环境、全量重跑、功能检查、基线门禁与续跑。
- [CodeNet 数据集评估](docs/CODENET.md)：导入、stdin/stdout oracle、手写组只检测的协议与报告工具。
- [真实仓库功能检查](docs/REAL_REPOS.md)：固定提交的大仓库上嵌入与逐规则全仓改写后运行自带测试。
- [鲁棒带密钥水印](docs/ROBUST_WATERMARK.md)：阶段 2 的方法、用法、评估配置与已知限制。
- [分支与版本管理](docs/plans/2026-10-07-branches.md)：本系列工作的分支地图、标签与服务器检出。
- [性能](docs/PERFORMANCE.md)：剖析结论、采用与放弃的优化、实测数据与修改指南。
- [论文与实现对照](docs/PAPER_ALIGNMENT.md)：两版论文与现有代码的对应关系。
- [实验记录](docs/experiments/) 与 [方案](docs/plans/)；[实验记录模板](docs/EXPERIMENT_TEMPLATE.md)。
- [机器可读代码索引](docs/code-index.json) 与 [论文来源记录](docs/paper-sources.json)。

## 注意事项

- 部分 C/C++ 规则沿用原实现的 `list(集合)[0]` 选取方式，输出依赖 Python 的字符串哈希种子。评估循环固定 `PYTHONHASHSEED`；在其他场景需要可复现输出时，请同样设置 `PYTHONHASHSEED`。
- tree-sitter 语法正确不等于语义等价：结构性质由 `tools/rule_audit.py` 审计，语义依据见规则目录，功能保持以真实测试验证。
- 论文报告的实验指标不等同于本地回归结果；本地结论以 `benchmark-results/` 下的运行记录与 `benchmarks/baselines/` 中的参考为准。
