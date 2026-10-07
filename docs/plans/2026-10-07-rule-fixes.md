# CodeNet 暴露的规则语义保持缺陷修复（v1）

## 目标与范围

CodeNet 评估（[实验记录](../experiments/2026-10-07-codenet.md)）中，对手写 C/C++/Python 嵌入水印造成 75（legacy）/98（extended）个功能回退，逐条重放后全部可由单条样式复现（[bisect legacy](../experiments/2026-10-07-codenet.bisect-file-legacy.json)、[bisect extended](../experiments/2026-10-07-codenet.bisect-file-extended.json)；逐例差异与编译错误见服务器 `/root/codenet-defects.txt`，摘要见下）。本方案修复这些规则，原则是**只拒绝会改变语义或语法的候选位置**（加守卫），不改变规则在其余位置的输出文本，以保持两个方向逐字节互逆。

**属于方法改动**（规则候选集合变化 → 容量、槽位与默认基准结果都会变化）。不改 BCH、嵌入/提取算法、槽位顺序、pairs.py。

## 缺陷、证据与修复

样本 ID 均为 `codenet_<lang>_human/<pid>`，语料在服务器 `/root/projects/CLLMark-codenet/external/codenet/dataset/{C,CPP,Python}_H/<pid>.<ext>`（本地 worktree 用 `make codenet-setup SOURCE=/private/tmp/claude-501/-Users-bytedance-Downloads-data-data/de27240c-b81d-4932-8a08-b391ac6ccd3f/scratchpad/dataset` 生成同样文件）。

### A. 宏重定义类型关键字（C/C++）

`#define int long long`（或 `long long int`、`#define double long double`）后，输出 `int`/`double` 的规则改变了类型：
- `main_style` 4.1/4.5：`signed main()` → `int main(void)` 展开为 `long long main` → 编译失败（17+17 例，如 cpp p00149、p00341）。
- `cast_style` 22.1：`(int)(x)` → `int(x)` 展开为 `long long int(x)` → 编译失败（cpp p03232）。
- `output` 9.2、`input` 9.4：按声明文本 `int` 选 `%d`，实际是 long long（cpp p02785、p03588、p02150、p01538、p02441、p03009、p03161）。

修复：在 `cllmark/rules/c.py` 新增守卫 `no_type_keyword_macro`：整个翻译单元中没有名字是内建类型关键字（`int long short char float double signed unsigned bool`）的 `#define`（tree-sitter `preproc_def`/`preproc_function_def` 的 name）。应用到 4.1–4.5、5.1/5.2（`array_init`，输出 `sizeof(int)`）、9.1–9.4、22.1/22.2。按文件计算一次（可缓存于根节点）。

### B. C++ 用户定义运算符（compound / 比较类规则）

用户类型只重载了部分运算符：`p = p - s` → `p -= s`（无 `operator-=`，10 例，如 cpp p01721、p02303、p00880）；`a == b` → `!(a != b)`（无 `operator!=`，cpp p00973、p01721）；`!(a == b)` → `a != b`（cpp p00880）。

修复：`cpp` 方言下，若翻译单元声明了任何运算符重载（`operator_name` 节点，或函数声明符名字以 `operator` 开头），则 2.1–2.14（self_assignment、equal/not_equal、reverse_compare、exp_cmp、hash 排序）全部拒绝。守卫名 `no_operator_overloads`，只在 `c_family_rules("cpp")` 中加入；C 方言不变。

### C. C++ 把比较误解析为模板实参

`a.y < b.y || … > 0` 被 tree-sitter-cpp 解析成 `y<…>` 模板实参，规则改写误解析的树：`reverse_compare` 2.7（cpp_generated p01843：生成 `table < for (…`）、`equal_hash_reverse` 2.12（cpp p02292：生成 `if (sign(...) > 0) == A.y {`）。

修复：实现者先打印这两例的解析树确认形状，然后新增守卫 `no_template_misparse`：候选节点所在语句（最近的 statement 祖先）内存在 `template_argument_list`，且其中含有 `binary_expression`（运算符为 `||`、`&&`、比较）或其父节点是 `field_expression`/`template_method` 的成员模板时拒绝。应用到 cpp 方言的 2.3–2.14（所有改写比较运算的规则）。若形状与上述不同，按实际形状写守卫并在回复中说明。

### D. `array_access` 5.3 优先级与记号（C/C++，14 例）

`a[i]` → `*(a + i)`：
1. 后缀上下文：父节点是后缀 `update_expression`（`a[i]++` → `*(a + i)++`）、`field_expression` 的对象（`a[i].x` → `*(a + i).x`）、`call_expression` 的函数位置时拒绝（c p00136、p00314、p00344、p01074、p02360、p03497、p03611、p03720、p00068、p00124、p00204）。前缀 `++a[i]`、`&a[i]`、嵌套下标保持现状。
2. 下标表达式优先级低于 `+`：下标是 `binary_expression` 且运算符不在 `+ - * / %` 中（移位、比较、位运算、逻辑）、或是条件/赋值/逗号表达式时拒绝（c p03185：`P[2<<17]` → `*(P + 2<<17)`）。`a[i-1]` 等保持。
3. 注释记号：节点前一个非空白字节是 `/` 时拒绝（c p02883：`mid/f[i]` → `mid/*(f + i)` 开始注释）。
4. 非良构：候选或其所在顶层项含 ERROR/MISSING 节点时拒绝（c p01283：K&R 全局 `o[256],z[256];` 被改成 `*(*(o + 256) + [)`）。确认现有 `well_formed` 为何没挡住，按需扩大检查范围到外层声明/语句。

`array_access` 的另一方向 5.4 同步加上对应的拒绝条件（输出 `a[i]` 不会出问题，但为保持候选集合互逆，5.4 只接受 5.3 能产生的形式：`*(a + i)` 中 i 满足第 2 条）。

### E. `array_init` 5.1：栈数组改 `malloc` 指针（C，2 例）

`int node[SIZE];` → `int *node = (int*)malloc(sizeof(int) * SIZE);`（c p00602 栈溢出检测、p03000 WA）。实现者先在这两例中找出依赖数组语义的用法（预期为 `sizeof node`/`sizeof(node)`、`memset(node, …, sizeof …)`、`&node`、或初始化列表），然后加守卫：该名字在其作用域内出现在 `sizeof` 操作数中、取地址 `&name`、或声明带初始化器、或为 `static`/文件作用域时拒绝。若根因不是这些，按实际原因写守卫并说明。

### F. `self_assignment` 2.2：副作用重复（C/C++）

`*ans++ += '0'` → `*ans++ = *ans++ + '0'`（c p01984）。修复：左操作数含 `update_expression`、`call_expression`、`assignment_expression` 或逗号表达式时拒绝（复用 `impure_syntax` 的概念或新写 `side_effect_free`）。对 2.1（`x = x op y` → `x op= y`）不需要（两边文本相同才匹配）。

### G. `self_assignment` 2.1 超时（cpp p01795、p03744）与 `exp_cmp` 2.9 WA（c p02876）

根因未确认。实现者对每例逐候选节点单独施加样式（节点级二分）找到肇事位置，写出最小复现，再加守卫。预期方向：2.1 可能是用户类型的 `operator+=` 语义/复杂度不同（若 B 已覆盖则说明）；2.9 可能是操作数含副作用（展开后操作数被求值两次）——若如此，给 2.9/2.10 加 `side_effect_free` 操作数守卫。

### H. `for_OOO` 7.7：无花括号的外层循环体（C/C++）

`for (i…) for (j=i+1; j<=B; j++) {…}` 的内层被改写成 `j=i+1; for(;;){…}` 两条语句，只有第一条留在外层循环内（cpp p03313）。修复：for 语句本身是 `for/while/do/if/else` 的无花括号子语句（父节点不是 `compound_statement`/翻译单元/`labeled_statement` 的语句列表）时拒绝。

### I. C++ 流 ↔ stdio 规则 9.1–9.4

逐条缺陷（cpp 样本）：
1. 9.1 `printf → cout`：
   - 有参数时格式串被截掉最后一个字符：`content.split('",')[0][1:-1]` 在 split 已去掉结尾引号后又去掉一个字符，`"%d\n"` 变成 `%d\`，输出 `cout << x << "\";`（p00057、p00161、p00353、p01418、p02328、p03035、p03409、p03694）。改为从语法树取格式串字面量与实参节点（`argument_list` 的命名子节点），不再按文本切分。
   - 带标志/宽度/精度或浮点的说明符（`%.15f`、`%5d`、`%f`、`%e`、`%g`、`%lf`）与 cout 默认格式不等价：拒绝。只接受 `%d %i %s %c %ld %lld %u` 且实参类型可由声明确定并与说明符一致（与 9.2 共用类型表），否则拒绝；`%c` 只接受 char 类型实参。
2. 9.3 `scanf → cin`：
   - 调用的值被使用（`if (scanf(...) <= 0)`，p00081）：只接受父节点是 `expression_statement` 的调用。
   - 格式串只能由说明符和空白组成；含其他字符（`%lf,%lf`）、`%c`、`%[`、宽度、`%*` 时拒绝。
   - 实参必须是 `&名字`、`&名字.字段`、`&名字[下标]` 或 char 数组名；`d+1` 之类拒绝。
3. 9.2 `cout → printf`：double/float（cout 默认 6 位有效数字，`%f` 为 6 位小数）拒绝；文件出现 `setprecision`、`fixed`、`setw`、`<< hex` 等流操纵符时拒绝。
4. 9.4 `cin → scanf`：
   - double 用了 `%f`（应为 `%lf`）：p00058、p01843。scanf 方向 double → `%lf`，long double → 拒绝。
   - `std::string` 用 `%s` 与 `&str`（p00963、p02777、p02289、p03107、p01008）：现有 `string` 检查在加 `&` 之后执行而失效；改为在加 `&` 之前检查并拒绝。
   - 内外层同名声明时外层覆盖内层（`visible.update` 从内向外），改为内层优先（已存在的名字不覆盖）。
   - 文件中 `cin` 出现在非 `cin >> …;` 语句的位置（`while (cin >> n)`、`cin.eof()`、`if (!cin)` 等）时拒绝（p00028 超时、p02953）。
5. 四条规则共同：翻译单元出现 `sync_with_stdio` 或 `cin.tie`/`cout.tie` 时拒绝（混用会乱序或读错，p02760、p03162）；9.1/9.3 要求文件 `#include <iostream>` 或 `<bits/stdc++.h>` 且有 `using namespace std;`（p00115、p00353、p01283、p03005、p03738：`cin`/`cout` 未声明）；再加 A 的宏守卫（p03600、p02584 预期由 A 覆盖，若不是请说明）。

### J. Python 记号粘连（list 2.3、f_string 6.3）

`for _ in[0]*3` → `inlist([0])*3`（py p00391）、`return[...]` → `returnlist(...)`（py p02298）、`or"NO"` → `orf"NO"`（py p00963）。修复：在 `cllmark/rules/python.py` 新增守卫 `not_after_word_character`：节点起始字节的前一个字节是字母、数字或 `_` 时拒绝。应用到 2.3 与 6.3，并检查其他在节点前插入标识符字符的 Python 规则（如 2.1 `dict`、`print_*`、`sum_start` 等在节点前加名字的样式），一并加上。另一方向（2.4、6.4）删除前缀后不会粘连，不需要。

## 测试与审计

- 新测试放在 `tests/test_rule_fixes.py`（不要改 `tests/test_rule_engine.py` 的已有用例）：上面每一类至少一个最小反例（改写前后都用最小代码片段，断言规则不改写该位置）和一个仍应改写的正例。I 类中 9.1 的格式串修正要有正例（`printf("%d\n", x)` 在类型已知时得到 `cout << x << "\n"`）。
- 对每个改动的水印对运行 `tools/rule_audit.py`，修改前后各一次：`--language c --pairs array_access,array_init,self_assignment,exp_cmp,for_OOO,main_style`，`--language cpp --pairs …（同上加 output,input,cast_style,equal_to_not_equal,not_equal_to_equal,reverse_compare,equal_hash_reverse,not_equal_hash_reverse）`，`--language python --pairs list,f_string`。完整输出写入 `docs/plans/2026-10-07-rule-fixes.audit-{before,after}.{c,cpp,python}.txt`。验收：after 中幂等、可逆、语法三项不比 before 差；候选数下降如实记录。
- 复现验证：对上面列出的每个样本 ID，在本地用 `cllmark.transform.StyleTransformer(lang, rule_set="extended").apply(style, code)` 施加肇事样式，结果要么与原文相同（被拒绝），要么能通过编译（C 用 `cc -std=c11 -fsyntax-only`，C++ 用本机编译器即可；macOS 上的 `std::stdin`/`bits` 问题不计）。把逐例结果写入 `docs/plans/2026-10-07-rule-fixes.repro.tsv`（列：id、style、before_fix、after_fix）。
- `make lint`、`make test` 通过。

## 禁止事项

- 不改 BCH、`cllmark/watermark.py`、`directories.py`、`nodes.py` 的算法，不改 `pairs.py` 的槽位顺序，不改 benchmarks/ 下的度量协议文件。
- 不删除语料或测试样本；不把整个规则停用来“修复”（只加位置级守卫，B 的文件级守卫是方案明确允许的例外）。
- 不运行全量 benchmark；不改基线。
- 修复后若规则输出文本需要变化（而不仅是拒绝），停下来列入待决问题。
