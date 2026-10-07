# 规则修复（鲁棒水印全量运行暴露的 C/C++ 位置缺陷，2026-10-08）

## 1. 背景与证据

鲁棒水印全量运行（`claude/robust-watermark` 提交 `e95fe921`，服务器 `/root/projects/CLLMark-robust`，运行 `20261007T2000…`–`T2054…`）在 CodeNet 生成代码上出现功能回退：8 个带密钥变体各 14–43 个（BCH 基线为 0）。原因是带密钥嵌入改写全部选中位点，而 BCH 只改写 7 个槽位，触及了此前未覆盖的位置。

归因用 `docs/experiments/2026-10-08-robust.bisect.py`：对每个回退单元，把规则集的每个样式单独在干净代码上全文件施加，用 CodeNet oracle 判定。224 个回退（8 个变体之和）中只有 1 个不能由单个样式复现。按变体计数：

| 样式 | 各变体回退数 | 失败形式 |
|---|---|---|
| `cast_style/22.1`（C++） | 13–23 | `(void)x;` → `void(x);`：语句开头的函数式转换被解析为声明（编译错误） |
| `array_init/5.2` | 0–19（只在 tok 变体） | `T *p = malloc(...)` → `T p[n]`：指针被存入结构体/别名、`n` 为运行时值（栈上 VLA）→ 运行时崩溃 |
| `array_access/5.3` | 0–4 | `p->cells[to][k]` → `*(*(*(p + cells) + to) + k)`：`array_dimension` 把成员访问也算作维数 |
| `conditional_order/15.2` | 0–2 | C++ 文件中的错误恢复区（模板尖括号误解析）里的条件表达式片段 `0 ? s[n-1] : 0` 被取反 |
| `exp_cmp/2.10` | 0–1 | `if (n <= 0 && n == 0)` → `if n < 0 {`：任意 `&&/||` 配对都被当作展开式，且删掉了 `if` 的括号 |
| `while_to_for/7.8`（C++） | 0–1 | `while (r.count < 8 && seek < cursor)` 被误解析为模板实参，改写删除了其后整个结构体 |
| `array_init/5.1` | 0–1 | 见第 3 节（原程序未定义行为） |

另外检查到 `for` 循环样式 7.2–7.6 的潜在缺陷（本轮未出现回退）：把更新式 `c` 移到循环体末尾时，循环体中的 `continue` 会跳过它；无花括号的循环体会把插入的语句移出循环。7.7 已拒绝这两种情况，其余样式没有。

## 2. 修复（只拒绝位置，规则在其余位置的输出不变）

- **A** `cast_style/22.1`：新守卫 `not_statement_start`，转换表达式位于表达式语句开头时拒绝。
- **B** `conditional_order/15.1/15.2`：新守卫 `whole_conditional`（条件表达式不能是二元/一元/转换等更紧运算符的直接操作数，否则是误解析）与 `outside_error_recovery`（祖先不能是 ERROR 节点）；C++ 另加 `no_template_misparse`。
- **C** `exp_cmp/2.10`：只收缩展开式实际写出的四种形式（`< ||==`、`> ||==`、`<= && !=`、`>= && !=`），且括号不是 `if`/`while`/`do`/`switch` 的条件括号。
- **D** `array_access/5.3`：下标链的底必须是标识符。
- **E** `array_init/5.2`：除原有的 free/realloc/return/重新赋值外，再拒绝：指针值被存储（赋值右侧、初始化器，含经过括号/转换/条件/±偏移）、自增自减、`sizeof`/`&`；元素数必须是不超过 4096 的整数字面量（运行时大小在栈上可能溢出）。
- **F** C++ 循环 7.1–7.8（含反向目标）：加 `no_template_misparse`。
- **G** `for` 循环 7.2–7.6：`condition_to_break` 要求花括号循环体；`update_to_end` 要求花括号循环体且无属于本循环的 `continue`。

测试：`tests/test_rule_fixes_robust.py`，每类一个来自归因的最小反例与一个仍须改写的对照。

## 3. 不属于规则缺陷的回退

- `codenet_c_generated/p03564`（`array_init/5.1`）：原程序 `logic_minimum_table` 在 `steps >= 32` 时写 `table[index + 1]` 越过 `long table[32]`；在栈上不报错，改到堆上被 glibc 检出。原程序未定义行为。
- `codenet_c_generated/p03435`（只在组合中出现）：把 `grid[r][c] = values[i];` 改成等价的 `*(*(grid + r) + c) = *(values + i);` 后 `-O2` 输出改变；`-O0`、ASan/UBSan 与 `-O2 -fno-strict-aliasing` 均输出正确答案。原程序违反严格别名规则，等价改写改变了优化结果。

## 4. 性质与验收

方法改动（规则位置）。默认语料与 CodeNet 的 BCH 结果会随可嵌入位置变化，按 AGENTS.md 需要重新运行：

1. `make lint`、`make test`（服务器）。
2. 默认四个配置对服务器参考 `/root/baselines/`：无新增功能回退；可嵌入单元的变化说明来源。
3. CodeNet 四个 BCH 配置：功能回退不增加。
4. 鲁棒水印 10 个配置全量：生成代码功能回退只剩第 3 节所列或新的可解释项；对 A–G 涉及的单元逐一确认已不回退。
5. `make repo-instant`、`make repo-check`：全部变体通过。
