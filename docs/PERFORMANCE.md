# 性能：剖析、取舍与基准

本文记录 2026-10-06 的性能工作：先剖析代表性负载、再按实测收益选择方案。结论是保留纯 Python 实现并做针对性优化；编译（mypyc）与更换解释器（PyPy）经实测不值得引入。

## 代表性负载与测量方法

[`tools/perf_benchmark.py`](../tools/perf_benchmark.py) 复现评估循环每个单元的 CPU 工作（不含功能测试）：分析、规则性质（幂等、可逆、互不干扰）、语法检查、嵌入、四次提取（原始、嵌入后、两次翻转攻击）。样本为每组固定随机抽取 12 个单元（共 292 个，覆盖 25 组、4 种语言）；`PYTHONHASHSEED` 固定为评估循环的 20261005，保证规则输出可复现。

```bash
make perf                                                     # 默认样本，best of 3
.venv-benchmark/bin/python tools/perf_benchmark.py --per-cohort 12 --repeat 3 --json perf.json
.venv-benchmark/bin/python tools/perf_benchmark.py --repeat 1 --profile profile.txt   # cProfile（按自身耗时排序）
```

输出：解释器、各阶段耗时（best of N）、新进程启动耗时（导入 + 四种语言各建一个 `StyleTransformer`）、峰值常驻内存。需要语料子模块与固定语法库（`make corpus setup-benchmark`）。

## 剖析结论

在原实现（`c2a0a16f`）上剖析，CPU 时间主要分布在：

| 部分 | 占比（cProfile 下） | 性质 |
| --- | --- | --- |
| chardet 编码检测 | 约 42% | 依赖库；对同一内容反复检测，且把 5 个 UTF-8 文件误判为 Windows-1252/1254 |
| 编辑冲突检查 `apply_edits` | 约 13% | 稳定引擎；两两比较，单个样本 4,300 万次 |
| tree-sitter 解析与查询 | 约 11% | 已是 C 实现 |
| 引擎的 Python 开销（捕获分组排序、守卫分派、解析缓存） | 约 15% | 稳定引擎 |
| 规则逻辑（守卫、改写、JavaScript 文件级事实） | 其余 | 经常修改的扩展点 |

稳定且影响性能的部分是 `cllmark/rules/engine.py`、`cllmark/transform.py`、`cllmark/watermark.py`、`cllmark/source_io.py`；经常修改的是各语言规则（`cllmark/rules/{python,c,cpp,javascript}.py`）、水印对、样式目录、评估配置与评估协议代码。

## 采用的优化（均为纯 Python，行为不变）

| 改动 | 位置 | 依据 |
| --- | --- | --- |
| 源文件统一为 UTF-8/LF，读取不再做编码检测，移除 chardet | `source_io.py`、数据仓库 `provenance/normalize_sources.py` | 去掉最大热点；同时修正 5 个文件的误读（唯一的结果变化） |
| 冲突检查改为有序索引（二分查找），重叠时回退两两比较 | `rules/engine.py::_AcceptedEdits` | 随机测试与原实现逐字节一致，含同位插入次序 |
| `apply` 只在文本确有变化时比较去空白文本 | `transform.py` | 多数探测不改变代码 |
| 守卫直接调用测试函数；捕获分组改为单次遍历，排序延迟到首次查询 | `rules/engine.py::Matcher.accepts`、`Parsed` | 每个候选节点、每次解析都执行 |
| 每个 `StyleTransformer` 缓存最近 1,024 次 `(样式, 代码)` 改写结果 | `transform.py` | 分析、性质检查与提取重复同样的改写；改写是确定性的 |

正确性：每一步都用等价性快照验证——28,898 个语料文件 × 全部样式的改写结果，以及 10,810 个单元的分析/嵌入/提取结果，与优化前逐项比较；除 UTF-8 修正涉及的 5 个文件与 4 个单元外完全相同。

## 实测结果

同一 292 单元样本、同一机器与解释器（CPython 3.11），best of 3，未开剖析器：

| 版本 | 总耗时 | 相对原实现 | 导入 | 四种语言建 transformer | 峰值内存 |
| --- | ---: | ---: | ---: | ---: | ---: |
| 原实现 `c2a0a16f` | 54.0 s | 1.00× | 113 ms | 43 ms | 248 MB |
| 打包 + 冲突索引 + UTF-8（`dc96878e`） | 30.5 s | 1.77× | 95 ms | 37 ms | 215 MB |
| + 引擎微优化 | 27.0 s | 2.00× | 100 ms | 34 ms | 233 MB |
| + 改写缓存（最终） | 24.7 s | 2.19× | 91 ms | 36 ms | 275 MB |

各阶段（原实现 → 最终）：性质检查 25.6 → 17.3 s，嵌入 16.6 → 1.1 s，分析 4.6 → 3.1 s，提取 3.9 → 2.3 s。改写缓存以约 40 MB 内存换约 9% 时间；缓存 4,096 项与 1,024 项速度相同但内存更高，256 项变慢。

## 评估过但未采用的方案

| 方案 | 实测 | 结论 |
| --- | --- | --- |
| mypyc 编译稳定模块（`rules/engine.py`、`watermark.py`、`bch.py`） | 27.0 → 26.5 s（约 2%），等价性快照完全一致 | 不采用：收益不足以抵消构建依赖（mypy、C 编译器）、按平台构建轮子与回退路径的维护成本。剩余时间主要在 tree-sitter（已是 C）与需要保持易改的规则逻辑中 |
| PyPy 7.3.15（Python 3.9，本环境唯一可安装版本） | 142.7 s（慢 5.3×），峰值内存 8,971 MB，导入 244 ms | 不采用：tree-sitter 0.20.2 是 CPython C 扩展，在 PyPy 中经 cpyext 访问每个节点，开销远超 JIT 收益；且项目要求 Python ≥ 3.11 |
| 选择性 C/C++ 实现 | 未实现 | 可加速的稳定引擎部分在优化后已不足总时间的五分之一；按 Amdahl 定律，即使完全消除也只有有限收益，而原生代码会成为引擎改动的负担 |
| 升级 py-tree-sitter（≥ 0.22，在 C 中按捕获名分组） | 未实现 | 需要改变语法库构建方式与环境，影响评估协议的可比性；适合与语法版本升级一起单独评估 |

## 兼容性与限制

- 支持的环境不变：CPython 3.11（tree-sitter 0.20.2 只为 CPython ≤ 3.11 提供预编译轮子；更高版本需要从源码编译 tree-sitter，且其 `Language.build_library` 依赖 distutils）。项目本身保持纯 Python，没有新增编译步骤或二进制产物；语法库仍由 `make setup-benchmark` 构建（需要 C 编译器）。
- 改写缓存按 `StyleTransformer` 实例保存，进程内有效；`StyleTransformer(language, cache_size=0)` 可关闭（每次都重新改写）。
- 源文件必须是 UTF-8；非 UTF-8 文件会报错并给出路径，而不是被猜测编码。

## 修改指南

- **规则**（`cllmark/rules/{python,c,cpp,javascript}.py`）：直接修改 Python；保持改写是代码文本的确定性函数（改写缓存依赖这一点，现有测试 `test_rules_have_no_state_between_files` 检查规则无状态）。
- **引擎**（`cllmark/rules/engine.py`）：`Matcher.accepts`、`Parsed.__init__` 与 `apply_edits` 是热点；修改后运行 `make test`（含编辑冲突的随机等价测试）与 `make perf` 对比。
- **重新评估编译或其他解释器**：用 `tools/perf_benchmark.py` 在同一样本上比较；mypyc 的可行做法是 `mypyc --ignore-missing-imports cllmark/rules/engine.py cllmark/watermark.py cllmark/bch.py`（引擎已通过 mypy 类型检查），收益超过维护成本时再引入构建配置。
