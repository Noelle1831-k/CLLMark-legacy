# CLLMark — 旧版论文实现

本仓库保存 CLLMark 的旧版研究代码：通过可逆语义保持变换（RSPT）对 Python、C、C++ 和 JavaScript 代码进行后处理，嵌入和检测多比特水印，并使用 BCH(7,4,1) 进行编码与纠错。

规则层已重构为声明式引擎：每条规则由 tree-sitter 查询模式、具名守卫和锚定到节点的原子编辑组成，水印流程在内存中完成（每个文件读一次、写一次）。在原有规则对之外新增了语义保持规则（Python 25 对、C 21 对、C++ 22 对、JavaScript 15 对），并修正了原有规则中会改变程序行为的情形。详见 [规则引擎与规则目录](docs/RULES.md) 与 [实验记录](docs/experiments/2026-10-rule-engine.md)。

**版本定位：当前代码对应旧版论文《Detecting and Tracing LLM Code via Reversible Watermarking》。新版 TOSEM 草稿《CLLMark: Traceability-Enabled Watermarking for LLM-Generated Code》作为后续对照，尚不能据此认定本仓库已完整实现新版方法。** 代码与旧版论文之间也存在需要核对的实现差异，详见论文对照。

## 从这里开始

- [代码地图](docs/CODE_MAP.md)：模块职责、调用关系、数据流、规则扩展位置及实验入口。
- [规则引擎与规则目录](docs/RULES.md)：规则表示、约束执行、各语言规则及其等价性依据、新增规则的审计流程。
- [论文与实现对照](docs/PAPER_ALIGNMENT.md)：两版论文与现有代码的对应关系、已有能力和待补齐部分。
- [机器可读代码索引](docs/code-index.json)：主要源码的符号、行号、导入、文件摘要和本地依赖。
- [论文来源记录](docs/paper-sources.json)：本次对照使用的 PDF 文件名、标题、页数和 SHA-256。
- [科研循环与全量 benchmark](docs/RESEARCH_LOOP.md)：固定环境、19 组全量重跑、功能检查、基线门禁、续跑和自动触发。
- [实验记录模板](docs/EXPERIMENT_TEMPLATE.md)：记录假设、控制变量、结果和反例。

建议阅读顺序：`watermark_core.py` → `change_program_style.py` → `rule_engine.py` → 各语言 `rules.py` → `bch_utils.py`；目录级入口 `folder_transform_check.py`、`watermark_bit.py`、`watermark_extract.py` 是薄适配层。

## 目录概览

```text
.
├── rule_engine.py               # 规则表示、单次查询匹配、原子编辑与冲突处理、解析缓存
├── change_program_style.py      # SCTS：样式编号到规则的前端、语法检查、函数提取
├── watermark_core.py            # 内存中的分析、嵌入、提取
├── code_io.py                   # 与旧版一致的解码，每个文件读一次、写一次
├── folder_transform_check.py    # 目录级分析入口，写出 support_transform.json
├── watermark_bit.py             # 目录级嵌入入口
├── watermark_extract.py         # 目录级提取入口
├── bch_utils.py                 # 固定 BCH(7,4,1)
├── rule_dict_bit_acc.py         # 水印规则对及 0/1 到样式的映射（槽位顺序）
├── styleList.json               # 样式编号目录
├── python/ c/ cpp/ javascript/  # 各语言 rules.py
├── dataset/                    # MBXP/CodeNet 相关代码、JSONL 及实验材料
├── Python_func/ C_func/ C++_func/ # 项目代码拆分后的函数级语料
├── Python_func_test/            # Python 水印实验语料
├── data/                       # 保留的实验快照，部分入口使用 C 参数
├── test/ test_1/ test.py        # 示例代码及混淆矩阵计算脚本
├── docs/                       # 代码地图及论文对照
├── benchmarks/                 # 固定协议、真实旧算法适配、指标与基线
├── tests/                      # 流程有效性、功能执行和断点恢复检查
├── Makefile                    # 日常科研 loop 入口
└── tools/                      # 环境初始化、科研 loop CLI、代码索引
```

## 本地科研循环

```bash
make setup-benchmark  # 一次性安装 Python 3.11 独立环境并构建固定语法库
make setup-javascript # 一次性准备 lodash、JavaScript 小项目、14 个固定提交的中型仓库与 Exercism 题库（需要 Node.js、npm、pnpm 与网络）
make doctor
make smoke           # 流程测试 + 每组 2 个实验单元
make benchmark       # 代码改动完成后：更新索引、测试、全量运行、比较固定基线
```

默认全量为 25 组、10,810 个实验单元（git 工作树中的语料；含 JavaScript 6 组，其中 `js_repos`、`js_repo_files`、`exercism_js` 为真实中型仓库与 Exercism 参考解）。`make baseline` 仅用于首次建立参考；已存在参考时拒绝覆盖。`make watch-benchmark` 在前台监控变更并自动触发完整 loop。详细配置、指标分母、结果位置及续跑命令见[科研循环文档](docs/RESEARCH_LOOP.md)。

新入口在每次运行的副本中调用实际旧算法，保留容量不足和失败样本，校验源码及原始输入没有被更改。Python/C++ MBXP 使用本地真实功能测试；CodeNet 缺少 problem_id 映射，其他拆分项目缺少功能 oracle，结果明确记录为 N/A。不同语料组有重叠，汇总用于版本回归，论文分析应使用分组与明确的样本协议。

## 使用与验证边界

现有代码主要是研究脚本，许多参数直接写在文件中。请从仓库根目录运行主版本脚本，并先检查输入输出路径。`data/` 是另一个实验快照，不是主版本的 Python 包入口。

`folder_transform_check.py` 的旧主程序会删除不足 7 个可用规则的项目目录；`watermark_bit.py` 会覆盖输入代码。日常实验使用上面的 `make benchmark`，该入口仅修改每次运行的工作副本。

旧环境面向 Python 3.9，并固定使用 `tree-sitter==0.20.2`。`requirements.txt` 保留原始记录，其中 `python~=3.9.21` 是解释器版本记录，不能直接当作普通 pip 依赖安装；实际导入的 `matplotlib`、`networkx` 未列入其中。已有 `venv/` 包含 Windows 环境文件。新流程使用 `benchmarks/requirements.lock` 和 `benchmarks/toolchain.lock.json`，在 `.venv-benchmark` 中运行，避免使用旧二进制。更完整的旧环境限制见[代码地图](docs/CODE_MAP.md#运行前需要确认的事项)。

生成代码的 `openai_ml.py` 从环境变量读取 `OPENAI_API_KEY`，可通过 `OPENAI_BASE_URL` 设置原有兼容 API 服务地址。`.env.example` 仅用于说明变量，本项目不会自动加载 `.env`。该脚本在执行及导入时会读取数据并调用外部 API，运行前需要检查数据文件和模型参数。

代码索引只依赖 Python 标准库：

```bash
python3 tools/build_code_index.py
python3 tools/build_code_index.py --check
```

建库时完成源码静态解析、索引一致性及 BCH 编解码检查；后续本地实验以 `benchmark-results/` 下的独立运行记录和 `benchmarks/baselines/current.json` 为准。论文报告的实验指标不等同于本地回归结果。运行环境、完整实验输出、缓存、二进制构建产物及本地凭据通过 `.gitignore` 排除。
