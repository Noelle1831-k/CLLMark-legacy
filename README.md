# CLLMark — 旧版论文实现

本仓库保存 CLLMark 的旧版研究代码：通过可逆语义保持变换（RSPT）对 Python、C、C++ 代码进行后处理，嵌入和检测多比特水印，并使用 BCH(7,4,1) 进行编码与纠错。

**版本定位：当前代码对应旧版论文《Detecting and Tracing LLM Code via Reversible Watermarking》。新版 TOSEM 草稿《CLLMark: Traceability-Enabled Watermarking for LLM-Generated Code》作为后续对照，尚不能据此认定本仓库已完整实现新版方法。** 代码与旧版论文之间也存在需要核对的实现差异，详见论文对照。

## 从这里开始

- [代码地图](docs/CODE_MAP.md)：模块职责、调用关系、数据流、规则扩展位置及实验入口。
- [论文与实现对照](docs/PAPER_ALIGNMENT.md)：两版论文与现有代码的对应关系、已有能力和待补齐部分。
- [机器可读代码索引](docs/code-index.json)：主要源码的符号、行号、导入、文件摘要和本地依赖。
- [论文来源记录](docs/paper-sources.json)：本次对照使用的 PDF 文件名、标题、页数和 SHA-256。
- [Claude Code 多 agent 团队](docs/MULTI_AGENT_TEAM.md)：Opus 分析出方案、Sonnet 实现与重复性工作的协作配置（`/team`、`/analyze`）。

建议阅读顺序：`folder_transform_check.py` → `watermark_bit.py` → `watermark_extract.py` → `change_program_style.py` → 各语言 `config.py` → `bch_utils.py`。

## 目录概览

```text
.
├── change_program_style.py      # SCTS：解析、风格变换、匹配、函数提取
├── folder_transform_check.py    # 分析可用规则并写出 support_transform.json
├── watermark_bit.py             # BCH 编码与按规则嵌入水印
├── watermark_extract.py         # 双向变换探测、BCH 解码及匹配统计
├── bch_utils.py                 # 固定 BCH(7,4,1)
├── rule_dict*.py                # 规则对及 0/1 到子规则的映射
├── styleList.json               # 风格编号到语言算子分类的映射
├── python/ c/ cpp/              # Tree-sitter 规则实现和注册表
├── dataset/                    # MBXP/CodeNet 相关代码、JSONL 及实验材料
├── Python_func/ C_func/ C++_func/ # 项目代码拆分后的函数级语料
├── Python_func_test/            # Python 水印实验语料
├── data/                       # 保留的实验快照，部分入口使用 C 参数
├── test/ test_1/ test.py        # 示例代码及混淆矩阵计算脚本
├── docs/                       # 代码地图及论文对照
└── tools/build_code_index.py    # 使用标准库重新生成源码索引
```

## 使用与验证边界

现有代码主要是研究脚本，许多参数直接写在文件中。请从仓库根目录运行主版本脚本，并先检查输入输出路径。`data/` 是另一个实验快照，不是主版本的 Python 包入口。

`folder_transform_check.py` 的主程序会删除不足 7 个可用规则的项目目录；`watermark_bit.py` 会覆盖输入代码。进行实验时应先复制语料到单独的工作目录，再修改脚本参数。

旧环境面向 Python 3.9，并固定使用 `tree-sitter==0.20.2`。`requirements.txt` 保留原始记录，其中 `python~=3.9.21` 是解释器版本记录，不能直接当作普通 pip 依赖安装；实际导入的 `matplotlib` 未列入其中。已有 `venv/` 包含 Windows 环境文件，不适用于本机 macOS。更完整的环境限制见[代码地图](docs/CODE_MAP.md#运行前需要确认的事项)。

生成代码的 `openai_ml.py` 从环境变量读取 `OPENAI_API_KEY`，可通过 `OPENAI_BASE_URL` 设置原有兼容 API 服务地址。`.env.example` 仅用于说明变量，本项目不会自动加载 `.env`。该脚本在执行及导入时会读取数据并调用外部 API，运行前需要检查数据文件和模型参数。

代码索引只依赖 Python 标准库：

```bash
python3 tools/build_code_index.py
python3 tools/build_code_index.py --check
```

此次建库进行了源码静态解析、索引一致性检查和 BCH 编解码检查；未运行会改写数据的全量水印实验，也未重新验证论文中的实验指标。语料和结果文件保持原有组织方式，运行环境、缓存、二进制构建产物及本地凭据通过 `.gitignore` 排除。
