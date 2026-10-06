# 真实仓库功能保持检查（`make repo-check`）

水印方法由大量改写规则组成，语料单元（MBPP、CodeNet、JS 项目等）之外，还要在真实的 10 万行级代码仓库上用其自带测试检验“改写后功能不变”。`tools/repo_check.py` 对 `benchmarks/real_repos.json` 中固定提交的仓库执行下列变体，每个变体是准备好的检出的一份新副本：

| 变体 | 内容 |
| --- | --- |
| `clean` | 不改源码；测试必须通过，否则该仓库不可用于本次检查 |
| `watermark/<规则集>/<粒度>` | 把整个仓库当作一个项目嵌入消息（legacy/extended × file/node），检查期望消息提取，再构建并测试 |
| `stress/<规则集>/<样式>` | 一条样式改写**全部**源文件，再构建并测试；比水印只改 7 个槽位强得多，逐条规则检验语义保持 |

三档速度：

| 命令 | 耗时（4 个仓库，64 线程服务器） | 内容 |
| --- | ---: | --- |
| `make repo-instant` | 约 11 秒 | 全部样式（含 legacy）在全部源文件上改写并检查语法；4 种水印变体嵌入并提取；clean 与扩展规则文件粒度水印各跑一次 `smoke_test`（几秒的关键测试子集） |
| `make repo-check` | 约 7 分钟 | 默认 quick 模式：4 种水印变体 + `critical_styles`（全部扩展样式与曾在这些仓库出错的 legacy 样式）全仓改写，运行完整测试 |
| `tools/repo_check.py run --mode all --bisect` | 1 小时以上 | 每一条样式全仓改写并运行完整测试，失败变体二分到文件 |

日常修改先跑 `make repo-instant`；改动规则后跑 `make repo-check`；新增规则或大改时再跑 `--mode all`。

变体通过的条件是构建与测试命令都以 0 退出。测试失败会重跑一次（排除偶发失败）；两次都失败且给出 `--bisect` 时，对改动文件二分，找出单独就能让测试失败的文件（最多 3 个），差异写到 `diffs/`。并发的变体各用独立的 `TMPDIR`。

## 仓库

| 仓库 | 语言 | 固定版本 | 改写范围 | 源码行数 | 测试 |
| --- | --- | --- | --- | ---: | --- |
| networkx | Python | `networkx-3.4.2` | `networkx/**/*.py`（不含 `tests/`、`conftest.py`） | 112,005 | 全部 pytest（xdist） |
| zstd | C | `v1.5.6` | `lib/`、`programs/` 的 `.c`/`.h` | 89,588 | `make check`（playTests） |
| cppcheck | C++ | `2.16.0` | `lib/`、`cli/` 的 `.cpp` | 97,997 | `testrunner`（4,814 个测试） |
| mathjs | JavaScript | `v13.2.0` | `src/**/*.js` | 59,264 | `mocha test/unit-tests` |

测试只运行仓库自带的用例，不能删除用例或仓库来通过；测试代码本身不改写（它是功能判据）。

## 使用

```bash
make repo-setup                     # 克隆固定提交、安装依赖、预构建（.benchmark-cache/real-repos/）
make repo-instant                   # 秒级：语法、提取、关键测试
make repo-check                     # quick：水印变体与关键样式，完整测试
.venv-benchmark/bin/python tools/repo_check.py run --repo networkx --mode stress --rule-set extended --styles 45.2
```

结果在 `benchmark-results/real-repos/<时间>/`：`report.md`（每个仓库的水印变体与逐样式表）、`results.json`、失败变体的 `diffs/`。退出码非 0 表示有失败变体或 clean 失败。

## 发现并修复的规则问题（方法协议改动）

以下问题都是语料基准没有暴露、在真实仓库上让构建或测试失败的 **legacy 规则**，已修复并在 `tests/test_functional_safety.py` 中固定为回归用例。它们改变 legacy 规则的适用范围，所以 legacy 运行结果与修复前的基线不可直接比较（需要重新选定基线）。

| 规则 | 仓库 | 问题 | 修复 |
| --- | --- | --- | --- |
| Python 6.1/6.2 引号 | networkx | f-string 替换字段里的字符串改用外层引号，Python 3.12 前是语法错误 | 跳过 f-string 替换字段内的字符串 |
| Python 10.2 去元组括号 | networkx | 多行元组去括号后 `return` 在第一个换行处结束 | 跳过多行元组 |
| Python 7.1/7.2 复合赋值 | networkx | `nodes = nodes - {v}` → `nodes -= {v}` 原地修改调用方的集合/数组 | 只改写同一函数内也被赋数字字面量的变量 |
| Python 7.3–7.6 等式取反 | networkx | `A[A != 0]` 是数组掩码，`not (A == 0)` 对数组报错 | 只改写取真值的比较（if/while/assert 条件、and/or/not 操作数等） |
| Python 7.9/7.10 expcmp | networkx | 对数组 `and`/`or` 报错；堆元素 `<` 与 `==` 不一致；操作数求值两次 | 只改写取真值、与数字字面量或 `len(...)` 比较、操作数无副作用的比较 |
| C/C++ 4.x main 签名 | zstd | `main(int argc, char *argv[])` → `main(void)` 而函数体仍用 argv | 函数体使用将被删除或新增的参数名时不改写 |
| C 5.1/5.2 数组与 malloc | zstd | 已 free/返回/重新赋值的指针改成栈数组；`T *const p` 丢失变量名 | 只改写不受生存期约束的局部指针、不被 sizeof/& 使用的局部数组 |
| C/C++ 6.1 拆分声明 | zstd | `size_t const a = ...` 的 `const` 被当作声明符 | 按 declarator 字段拆分 |
| C++ 2.7/2.9 等比较规则 | cppcheck | `std::set<std::string> x;` 被 tree-sitter 误解析为比较后改写 | 跳过单独成句的比较与链式关系比较 |
| C/C++ 2.9/2.10 expcmp | cppcheck | 操作数含函数调用（求值两次）、重载运算符不构成一致的序 | 操作数无调用/赋值/自增；C++ 另需一侧为数字字面量 |
| JS 44.x 引号（扩展） | Exercism | 测试准备按文本匹配 import 路径，改引号后找不到模块 | 不改 import/export/require 的模块路径字符串 |

扩展规则集在全部仓库的逐样式全仓改写中没有失败。

## 局限

- 判据是仓库测试是否通过；测试覆盖不到的行为差异发现不了。
- 水印变体在这些仓库里只改 1 个文件（7 个槽位都落在项目顺序中第一个够用的文件），所以规则的语义风险主要由 stress 变体发现。
- 一些规则的风险依赖运行时类型（例如 `a = a - b` → `a -= b` 对集合、列表、numpy 数组是原地修改），语法层面无法判定，只能靠这类测试暴露并限制规则适用范围。
