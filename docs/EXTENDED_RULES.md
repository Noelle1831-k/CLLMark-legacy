# 扩展规则集（rule set "extended"）

默认规则集 `legacy` 是论文的规则对（`cllmark/rules/pairs.py` 的 `WATERMARK_PAIRS`），保持不变。`extended` 在其后追加扩展规则对，按需选择：

```bash
.venv-benchmark/bin/python -m cllmark embed DIR -l python -b 1010 -o OUT -r extended   # -g node 亦可
.venv-benchmark/bin/python -m cllmark extract OUT -l python -b 1010                    # 规则集从支持文件读出
.venv-benchmark/bin/python tools/research_loop.py loop --config benchmarks/config-extended.json
.venv-benchmark/bin/python tools/research_loop.py loop --config benchmarks/config-node-extended.json
```

规则对的候选来自 `REVERSIBLE_TRANSFORMATION_CATALOG_EN.csv` 中只依赖语法的条目（括号表示、操作数交换、字符串引号、尾随逗号、循环体花括号），按全语料调查中“能让容量不足 7 的单元变得可嵌入”的数量筛选。

## 规则对

bit 0 是语料中更常见的形式（`tools/rule_audit.py` 的 form0/form1 统计），未加水印的代码因此不会读成码字。

| 规则对 | 样式（bit 0 / bit 1） | 语言 | 形式 |
| --- | --- | --- | --- |
| `return_paren` | 40.1 / 40.2 | 全部 | `return E` ↔ `return (E)` |
| `literal_order` | 41.1 / 41.2 | 全部 | `x * 2` ↔ `2 * x`（C/C++/Python 还有 `+`；JS 只用 `*`，`+` 可能是字符串拼接） |
| `condition_paren` | 42.1 / 42.2 | Python | `if C:` ↔ `if (C):`（`elif` 同） |
| `trailing_comma` | 43.1 / 43.2 | Python | `[a, b]` ↔ `[a, b,]`（list/dict/set 字面量，单行） |
| `quote_style` | 44.1 / 44.2 | JavaScript | `'s'` ↔ `"s"`（内容不含引号、反斜杠） |
| `assignment_paren` | 45.1 / 45.2 | 全部 | `x = a + b` ↔ `x = (a + b)`（算术或位运算） |
| `loop_braces` | 46.2 / 46.1 | C++（range-for）、JavaScript | `for (...) { S; }` ↔ `for (...) S;`（两种排版，见 `cllmark/rules/braces.py`） |

## 设计约束

- **精确互逆**：每对两个方向在其接受的形式上互为逆变换，且幂等；只接受单行、无注释、间距规范的形式，改写不重排其他文本。
- **不改变 legacy 规则的候选**：扩展规则不碰比较的操作数（等式取反、哈希顺序、expcmp、关系镜像读操作数文本；检查一直向上到根，穿过 lambda/函数表达式）、`a = a <op> b`（复合赋值）、C 的下标与解引用（5.x）、Python 的元组/None 返回（10.x）、带 else 的 if（16.x 分支顺序只认不带括号的条件）、`and`/`or` 返回值（expcmp 7.10 读 `(a < b or a == b)` 的括号）、JS 的 `**`（27.x）、JS for/while 的“`while (c) `”头部（7.x）、C/C++ 的 for/while/do 循环体（7.7/7.8 读花括号）、C++ 的 `<<`/`>>`（9.x）。
- **嵌套候选**：操作数中含有另一个运算时不取外层候选（一次改写不会两次编辑同一段文本）；去括号只删除两个括号记号，嵌套的候选各自独立。
- 反方向（legacy 规则改写后让扩展规则的候选消失，例如 `if a == b:` → `if not a != b:` 后不再是 `condition_paren` 候选）仍然存在，与 legacy 规则之间已有的相互影响同类，由基准的恢复率度量。

## 审计（`tools/rule_audit.py --rule-set extended`）

扩展规则对在全部语料文件上：幂等失败 0，可逆失败仅出现在原本就有语法错误的文件（各语言 ≤1 个），扩展 → legacy 的干扰为 0（个别语法错误文件除外）。

## 结果

全量 10,810 单元，同一语料与 seed，源码摘要 `7580a2be`（服务器 64 线程，每次约 70–85 秒）。扩展运行的协议指纹因 `rule_set` 键不同，不与 legacy 基线比较门禁。

| 运行 | 容量覆盖 | 消息恢复 | TPR | FPR | 功能保持（配对） | 功能回归 |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| legacy · 文件粒度 | 52.21% | 99.65% | 99.84% | 2.13% | 99.76% | 1 |
| legacy · 节点粒度 | 60.64% | 100.00% | 100.00% | 3.55% | 99.90% | 1 |
| **extended · 文件粒度** | **63.59%** | 99.68% | 99.87% | 1.73% | 99.91% | 1 |
| **extended · 节点粒度** | **69.41%** | 100.00% | 100.00% | 3.95% | 99.94% | 1 |

唯一的功能回归是已知的 `js_repo_files/ejs/lib/utils.js`（测试比较函数源码文本）。legacy 文件粒度覆盖从 54.88% 降到 52.21%，原因是真实仓库检查后对 legacy 规则加的功能安全限制（见 `docs/REAL_REPOS.md`），其余指标基本不变。

真实仓库（`make repo-instant` / `make repo-check`）：全部扩展样式在 networkx、zstd、cppcheck、mathjs 上全仓改写后构建与完整测试通过；JS 引号规则不改模块路径字符串（Exercism 测试准备按文本匹配 import 路径）。
