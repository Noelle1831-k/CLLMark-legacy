# CLLMark — 旧版论文实现

本仓库是 CLLMark 旧版方法的实现：通过可逆的语义保持变换（RSPT）对 Python、C、C++ 和 JavaScript 代码做后处理，嵌入并检测多比特水印，使用 BCH(7,4,1) 编码与纠错；并附带可复现的全量评估循环。

规则层是声明式引擎：每条规则由 tree-sitter 查询模式、具名守卫和锚定到节点的原子编辑组成，水印流程在内存中完成（每个文件读一次、写一次）。在原有规则对之外新增了语义保持规则（Python 25 对、C 21 对、C++ 22 对、JavaScript 25 对），并修正了原有规则中会改变程序行为的情形。详见 [规则引擎与规则目录](docs/RULES.md) 与 [实验记录](docs/experiments/2026-10-rule-engine.md)。

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
│   ├── source_io.py            #   与原实现一致的解码（chardet 语义），一次读一次写
│   └── rules/
│       ├── engine.py           #   规则表示、单次查询匹配、原子编辑与冲突处理、解析缓存
│       ├── python.py c.py cpp.py javascript.py   # 各语言规则（RULES：样式编号 → Rule）
│       ├── pairs.py            #   水印规则对（顺序即槽位顺序）
│       └── styles.json         #   样式目录
├── benchmarks/                 # 评估协议：冻结运行、真实功能测试、指标、门禁与基线
├── tools/                      # 环境初始化、科研循环 CLI、规则审计、语料工具、代码索引
├── tests/                      # 单元与流程测试
├── docs/                       # 代码地图、规则目录、科研循环、论文对照、实验记录与方案
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

默认全量为 25 组、10,810 个实验单元（含 JavaScript 6 组）。每次运行在冻结副本中执行，保留容量不足和失败样本，并校验源码与原始输入没有被更改。Python/C++/JavaScript MBXP 与 Exercism 使用本地真实功能测试，JavaScript 仓库使用其自带测试套件；CodeNet 与拆分项目缺少功能 oracle，结果记录为 N/A。配置、指标分母、门禁与续跑见 [科研循环文档](docs/RESEARCH_LOOP.md)。

## 开发

```bash
make setup-dev   # 安装固定版本的 ruff
make lint        # ruff check + format --check
make format      # 自动修复与格式化
make test        # 单元与流程测试（缺少语料或 JavaScript 环境的测试自动跳过）
make code-map    # 重建 docs/code-index.json
```

CI（`.github/workflows/ci.yml`）在每次推送和 PR 上运行 lint 与测试。修改规则、度量或评估协议后需按 [AGENTS.md](AGENTS.md) 运行全量 benchmark；新增规则的审计流程见 [RULES.md](docs/RULES.md#新增或修改规则的流程)。

## 文档

- [代码地图](docs/CODE_MAP.md)：模块职责、调用关系与数据流。
- [规则引擎与规则目录](docs/RULES.md)：规则表示、约束执行、各语言规则及其等价性依据。
- [科研循环与全量 benchmark](docs/RESEARCH_LOOP.md)：固定环境、全量重跑、功能检查、基线门禁与续跑。
- [论文与实现对照](docs/PAPER_ALIGNMENT.md)：两版论文与现有代码的对应关系。
- [实验记录](docs/experiments/) 与 [方案](docs/plans/)；[实验记录模板](docs/EXPERIMENT_TEMPLATE.md)。
- [机器可读代码索引](docs/code-index.json) 与 [论文来源记录](docs/paper-sources.json)。

## 注意事项

- 部分 C/C++ 规则沿用原实现的 `list(集合)[0]` 选取方式，输出依赖 Python 的字符串哈希种子。评估循环固定 `PYTHONHASHSEED`；在其他场景需要可复现输出时，请同样设置 `PYTHONHASHSEED`。
- tree-sitter 语法正确不等于语义等价：结构性质由 `tools/rule_audit.py` 审计，语义依据见规则目录，功能保持以真实测试验证。
- 论文报告的实验指标不等同于本地回归结果；本地结论以 `benchmark-results/` 下的运行记录与 `benchmarks/baselines/` 中的参考为准。
