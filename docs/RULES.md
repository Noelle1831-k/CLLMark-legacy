# 规则引擎与规则目录

本文说明变换规则的表示方式、约束的执行位置、四种语言的规则目录（含新增规则的等价性依据）以及新增或修改规则时的检查流程。各阶段的实验证据见 [2026-10 重构实验记录](experiments/2026-10-rule-engine.md)。

## 一条规则由三部分组成

旧实现中每条规则是 `rec_*`（遍历所有节点、用多层 `if` 判断）、`cvt_*`（返回 `(字节位置, 插入串或删除长度)` 元组）以及登记在四处的编号；不适用的情况常靠抛出异常过滤（例如 `{'==': '!='}['!=']` 的 KeyError、`ret.append()` 的 TypeError）。现在每条规则是 [`cllmark.rules.engine.Rule`](../cllmark/rules/engine.py)：

| 部分 | 表示 | 执行位置 | 承担的约束 |
| --- | --- | --- | --- |
| `pattern` | tree-sitter 查询，`@node` 标记候选节点，`@_x` 为谓词辅助捕获 | 一种语言的全部模式编译成一个查询，C 层一次匹配 | 节点类型、字段、子节点形状、字面量（`#eq?`/`#not-eq?`/`#match?`；不支持的谓词在加载时报错，避免 0.20.2 静默忽略 `#any-of?`） |
| `guards` | 具名、可组合（`&`、`\|`、`~`）的 `Guard` | 按顺序短路求值；`Rule.explain(node)` 返回失败守卫名 | 祖先关系、文本比较、与其他规则的互斥区域、遮蔽内建名、版式 |
| `rewrite` | 返回锚定到节点的 `Edit`（`replace`/`insert_before`/`insert_after`/`delete`/`delete_between`） | 引擎按组原子应用 | 需要计算后才能判断的前置条件抛出 `Reject("原因")`；其他异常是规则缺陷，不被吞掉 |

引擎集中保证的不变量：

- **原子组与冲突**：一个候选的全部编辑构成一组；组按先序（外层优先）应用，与已接受组重叠或插入其内部的组被跳过；同一组内重叠视为规则缺陷并报错。旧的字节算术把同位置插入按长度倒序排列（`int a, bb;` 拆成 `int bb; int a;`）、在重叠时产生截断文本，并用字符数计算字节偏移。
- **字节偏移**：所有偏移是 UTF-8 字节偏移，插入长度按编码后的字节计算。
- **一次解析**：`Grammar.parse` 按代码文本缓存最近的解析树与全部规则的候选（LRU 8），分析阶段对同一文件探测几十个规则只解析、匹配一次。
- **只改变化的记号**：新增规则尽量只替换实际变化的记号（如 `o.p` → `o["p"]` 只替换 `.p`），嵌套链（`a->b->c`、`o.p.q`）的各层编辑互不重叠，一次应用即完成，满足幂等。

## 新增规则的约束

新增规则遵循以下规则，`tools/rule_audit.py` 在全量语料上检验：

1. **双向精确互逆**：两个方向互为逆变换（对其输出的规范版式逐字节可逆）；非规范版式（如 `int* a`、`(double) x`、`}\nelse{`）不作为候选，避免“规范化”造成不可逆。
2. **语义等价**：每对规则附带等价性依据（见下表），守卫排除依据不成立的情形。
3. **不干扰其他规则**：
   - 不进入任何比较运算（`==`/`!=`/关系运算）的操作数及展开比较 `(a < b || a == b)`：旧哈希排序规则读取 `==`/`!=` 操作数文本，`exp_cmp` 会把关系比较展开为等式；
   - 规则区域互斥，并按“形式不变”定义候选：例如“分支必然退出”同时识别 `if c: return a / return b` 和 `if c: return a else: return b`，使 else-after-return 与分支交换互不改变对方的候选；
   - 只改写无语法错误的子树（`well_formed`）。
4. **比特 0 为常见形式**：未加水印的代码读出全 0 码位，与非零水印的码字不同，降低误检。

## 规则目录

“水印对”是 [`cllmark/rules/pairs.py`](../cllmark/rules/pairs.py) 中的一项：`(比特 0 对应样式, 比特 1 对应样式)`。样式编号由 [styles.json](../cllmark/rules/styles.json) 给出名称；`11`/`12` 是 C/C++ 旧方法的检测型子规则（不改写代码，以 7.7/7.8 的目标形式是否存在判断）。

### 原有规则（Python 17 对，C 14 对，C++ 14 对）

保留原有候选条件与输出文本；差异只来自上文的编辑语义修正，以及下表的安全修正。

| 语言 | 规则 | 安全修正（只拒绝会改变程序行为或语法的位置） |
| --- | --- | --- |
| Python | `self_assignment` 7.2 `a += b → a = a + b` | b 的结合力不强于运算符时拒绝（`s += '0' if c else '1'` 原被改成 `s = s + '0' if c else '1'`） |
| Python | `string_quota` 6.1/6.2 | 内容含目标引号时拒绝（原规则把 `"it's"` 改成 `'it"s'`） |
| Python | `f_string` 6.3/6.4 | 含 `{`/`}` 或其他前缀（`B`/`R`/`U`）时拒绝（原规则生成 `f'{'`、`fB''`） |
| Python | `print_*` 1.1/1.3 | 生成器参数或尾随逗号时拒绝（原生成 `print(x,, flush=True)`） |
| Python | `range_index` 4.1 | `range(*args)` 拒绝 |
| Python | `list_index` 4.3/4.4 | `a[:-k] ↔ a[:len(a)-k]` 只用于名字 `a` 与正整数字面量 k（k=0 时两者不等） |
| Python | `return` 10.2 | `return ()` 拒绝（会变为返回 None） |
| Python | 在节点前后写入或删除字母的样式（`list` 2.1/2.3、`dict` 3.1/3.3、`f_string` 6.3、比较与否定 7.x、`not in`/`is not` 14.2/15.2 等） | 节点紧贴字母、数字或 `_` 时拒绝（`not_after_word_character` / `not_before_word_character`）：原规则把 `in[0]` 改成 `inlist([0])`、`or"NO"` 改成 `orf"NO"` |
| Python | `split_assignment` 9.1 | 按语法树取左右元素；元素个数不同、目标不是简单名字、左侧名字出现在右侧、右侧含调用/下标/属性/`await`/`yield`/海象时拒绝（`a, b = b, a` 拆开后不再交换）；语句不在行首或行缩进含制表符时拒绝 |
| Python | `self_assignment` 7.1 | 链式赋值拒绝（`S[i+1] = s = s + x` 改写后语法错误） |
| C/C++ | `self_assignment` 2.2 | 右侧为条件/赋值/逗号或结合力不强于运算符时拒绝（C 原把 `a *= b + c` 改成 `a = a * b + c`） |
| C/C++ | `update_reverse` 3.x | 只改写值未被使用的 `i++`（语句、for 更新子句）；原规则改写 `while (n--)`、`if (i++ > 3)` |
| C/C++ | `declare` 6.1 | 带定义体的 struct/union/enum、含语法错误节点的声明拒绝（原规则复制类型定义，并把误解析的片段拆成 `int, i;` 之类的残片） |
| C/C++ | `declare` 6.2 | 相邻声明（之间只有注释或已并入的声明）不限制初始值：声明符结束处有序列点，`int a = x, b = y;` 与分开声明等价。后续声明需跨越语句上移时，只有同时满足以下条件才并入：初始值与数组长度只含无副作用的表达式（标识符、字面量、`+ - * 比较 逻辑 & \| ^`，不含 `/ % << >>` 与调用）；被跨越节点不出现这些标识符与被声明的名字，不含调用、经指针/下标/成员或 C++ 引用的写入、标签/`case`/`goto`、语法错误；声明位于花括号块内。另外跳过 `auto`/`decltype`、含 `volatile`/`constexpr`/`extern`/多个限定符的组（合并后的类型文本不携带它们）、含语法错误的声明，以及同时含一维与多维数组声明符的组（`array_init` 的 5.1 会因多维数组拒绝整条声明，造成干扰）；声明不在行首时不补缩进（原规则每次多出空格） |
| C/C++ | `for_OOO` 7.7 | 无花括号的循环体或含本循环 `continue` 时拒绝（原规则使更新被跳过或语句移出循环） |
| C/C++ | `while_to_for` 7.8 | 计数更新是循环体最后一条语句且无 `continue` 时移入 for 头部；否则更新留在循环体内，头部第三子句为空（`for(int identifier = 1; c; )`，与 while 等价）；拒绝 do-while 与已使用标记名的循环 |
| C/C++ | `main_style` 4.1–4.5、`array_init` 5.1/5.2、`cast_style` 22.x、9.1–9.4 | 文件中有名字是内建类型关键字的 `#define`（`#define int long long`）时拒绝：规则输出的 `int`/`double`/`sizeof(int)` 会被宏改变类型；主函数体是 function-try-block 时 4.x 拒绝 |
| C++ | 2.1–2.14 | 文件声明了任何运算符重载（`\boperator\b`）时拒绝（用户类型可能只重载部分运算符，`operator+=` 的函数体 `*this = *this + b` 会被改成自递归）；比较被 tree-sitter-cpp 误解析为模板实参、或候选含语法错误时拒绝（`no_template_misparse`） |
| C/C++ | `self_assignment` 2.1/2.2 | 目标含 `++`/调用/赋值/逗号时拒绝（`*p++ += c` 改成 `*p++ = *p++ + c` 求值两次）；两个方向同守卫以保持互逆 |
| C | `array_access` 5.3/5.4 | 5.3：下标位于后缀 `++`/`--`、成员访问对象、调用位置时拒绝（`*(a + i)++`）；任一下标优先级低于 `+`（移位、比较、位运算、逻辑、条件、赋值、逗号）时拒绝；前一个非空白字符是 `/` 时拒绝（`mid/*(f + i)` 成注释）；所在顶层项含语法错误时拒绝（原 5.3 没有 `well_formed`）。5.4：`*(a - i)` 不是 `a[i]`，加号必须紧邻基址；同样要求顶层项无语法错误 |
| C | `array_init` 5.1 | 文件有 `#include` 但没有 `stdlib.h`/`malloc.h` 时拒绝（隐式声明的 `malloc` 返回 int，指针被截断）；无任何 `#include` 的片段由外层测试代码提供头文件，不受限 |
| C/C++ | `for_OOO` 7.7 | for 语句不是语句块、`case` 或翻译单元的直接子语句（无花括号的 for/while/if/else 子语句）时拒绝：上提的 `a;` 会留在循环外 |
| C++ | `output`/`input` 9.1–9.4 | 只转换整句、说明符限于 `%d %i %s %c %ld %lld %u`（9.3 另有 `%lu %llu %lf %f`，无标志/宽度/精度/`%c`/`%[`/`%*`/`%i`），实参类型由可见声明（内层优先）确定并与说明符一致，double/float 与 `std::string`/`short`/`char` 标量不转换；格式串与实参取自语法树；值被使用的调用、文件中 `sync_with_stdio`/`tie`、流操纵符、`cin` 的其他用法、重定义的 I/O 名字时拒绝；四条规则都要求 `iostream`（或 `bits/stdc++.h`）与 `using namespace std;`（无任何 `#include` 的片段除外），保证两个方向互为逆 |
| C++ | `cast_style` 22.1 | 转换位于表达式语句开头时拒绝（`(void)x;` 改成 `void(x);` 是声明，最令人烦恼的解析）（2026-10-08） |
| C/C++ | `conditional_order` 15.1/15.2 | 条件表达式是二元/一元/转换等更紧运算符的直接操作数、或位于 ERROR 恢复区时拒绝（C++ 把 `x < y ? a : b` 误解析后只否定了 `y`）；C++ 另加 `no_template_misparse`（2026-10-08） |
| C/C++ | `exp_cmp` 2.10 | 只收缩展开式写出的四种形式（`< \|\| ==`、`> \|\| ==`、`<= && !=`、`>= && !=`），括号是 `if`/`while`/`do`/`switch` 的条件括号时拒绝（原规则把 `if (n <= 0 && n == 0)` 改成 `if n < 0`）（2026-10-08） |
| C | `array_access` 5.3 | 下标链的底必须是标识符（`p->cells[i][j]` 原被改成 `*(*(*(p + cells) + i) + j)`）（2026-10-08） |
| C | `array_init` 5.2 | `malloc` 指针改数组时，除 free/realloc/return/重新赋值外，指针值被存储（赋值右侧、初始化器）、自增自减、`sizeof`/`&` 时拒绝；元素数必须是 ≤ 4096 的整数字面量（运行时大小的栈上数组可能溢出）（2026-10-08） |
| C++ | 循环 7.1–7.8 | 加 `no_template_misparse`（`while (r.count < 8 && seek < cursor)` 被误解析为模板实参，改写删除了其后的结构体）（2026-10-08） |
| C/C++ | `for_OOO` 7.2–7.6 | 把条件移入循环体要求花括号循环体；把更新移到循环体末尾另要求没有属于本循环的 `continue`（与 7.7 一致）（2026-10-08） |

### 新增规则

| 语言 | 水印对（比特 0 / 1） | 两种形式 | 等价性依据与关键守卫 |
| --- | --- | --- | --- |
| Python | `membership_negation` 14.1/14.2 | `x not in y` / `not x in y` | 比较运算优先级高于 `not`，后者解析为 `not (x in y)`；只用于单个比较 |
| Python | `identity_negation` 15.1/15.2 | `x is not y` / `not x is y` | 同上 |
| Python | `branch_order` 16.1/16.2 | `if c: A else: B` / `if not c: B else: A` | c 为名字/属性/调用/下标；两块同缩进、均不必然退出、不含嵌套 if/else |
| Python | `conditional_order` 17.1/17.2 | `a if c else b` / `b if not c else a` | b 不是条件表达式或 lambda；不含嵌套条件表达式；操作数原位交换保持版式 |
| Python | `sum_start` 18.1/18.2 | `sum(x)` / `sum(x, 0)` | 内建 `sum` 的 start 默认值为 0；模块内未重新绑定 `sum`，参数无解包 |
| Python | `range_step` 19.1/19.2 | `range(a, b)` / `range(a, b, 1)` | step 默认 1；a 不是 0（与 `range_index` 区域互斥），`range` 未被重新绑定 |
| Python | `loop_exit` 20.1/20.2 | `while C:` / `while True: if not C: break` | 每次迭代都在同一点检验 C，`continue` 也回到检验点；无 else；C 可安全前置 `not`，且不是 `x in y` 或括号内的相等比较 |
| Python | `else_after_return` 21.2/21.1 | `if c: …return` + 余下语句 / `if … else: 余下语句` | 分支必然退出时余下语句只在条件为假时执行；块内唯一的必然退出 if，移动区域内无其他必然退出 if、无多行字符串 |
| C/C++ | `branch_order` 14.1/14.2 | `if (c) {A} else {B}` / `if (!(c)) {B} else {A}` | c 不是 `==`/`!=`、展开比较或已取反形式；两块均为花括号块、不含嵌套 if/else |
| C/C++ | `conditional_order` 15.1/15.2 | `c ? a : b` / `!(c) ? b : a` | a、b 非逗号/赋值；无嵌套条件表达式；原位交换 |
| C/C++ | `nested_condition` 16.1/16.2 | `if (a && b) {S}` / `if (a) if (b) {S}` | 短路求值一致；无 else（避免悬挂 else）；a、b 不含 `&&`/`\|\|`；非展开比较；规范空白 |
| C/C++ | `array_parameter` 17.2/17.1 | `T *a` / `T a[]`（形参） | 数组形参调整为指针；仅内建非 void 元素类型（不完整 struct 或 void 数组非法）；排除 main |
| C/C++ | `void_return` 18.1/18.2 | 函数体末尾无 / 有 `return;` | void 函数执行到末尾即返回；排除 main |
| C | `member_access` 19.1/19.2 | `p->x` / `(*p).x` | C 中 `E1->E2` 定义为 `(*E1).E2`；对象为名字/成员/调用；不在 `*(...)`、下标内（数组规则统计这些） |
| C/C++ | `else_after_return` 20.2/20.1 | `if {…return}` + 余下语句 / `if {…} else {余下语句}` | 同 Python；余下语句不含声明（作用域）；排除 main 与 void 函数顶层块（与 main/void_return 规则互斥） |
| C++ | `type_alias` 21.2/21.1 | `typedef T N;` / `using N = T;` | 别名声明与 typedef 语义相同；T 为简单类型 |
| C++ | `cast_style` 22.2/22.1 | `(T)x` / `T(x)` | 单一类型名的函数式转换定义为等价的 C 风格转换；T 为单词内建类型；不直接作为 `<<`/`>>` 流操作数 |
| JavaScript | `self_assignment` 2.1/2.2 | `x += y` / `x = x + y` | x 为名字（求值无副作用）；y 为初等表达式（无优先级变化） |
| JavaScript | `equal_to_not_equal` 2.4/2.3、`not_equal_to_equal` 2.6/2.5 | `a === b` / `!(a !== b)` 等 | `!==`/`!=` 的定义即对应相等运算的取反 |
| JavaScript | `reverse_compare` 2.7/2.8 | `x > 0` / `0 < x` | 一侧为字面量时 ToPrimitive 只作用于另一侧，求值次序不可观察 |
| JavaScript | `equal_hash_reverse`、`not_equal_hash_reverse` 2.11–2.14 | 按 SHA-256 排列相等比较操作数 | 相等比较对称；操作数为名字或字面量 |
| JavaScript | `update_reverse` 3.2/3.1 | `i++` / `++i` | 只在值未使用处（语句、for 更新子句） |
| JavaScript | `declare` 6.1/6.2 | 每个声明一条 / 连续同类声明合并 | 声明按原顺序求值，TDZ 不变；按“簇”（相邻行、同缩进、同关键字、单行规范版式的声明）整体拆分或合并 |
| JavaScript | `loop_form` 7.1/7.2 | `while (c) S` / `for (; c; ) S` | 无初始化与更新的 for 与 while 等价；只取规范版式 |
| JavaScript | `branch_order`、`conditional_order`、`nested_condition` 14–16 | 同 C | `!( )` 即 if/?: 使用的 ToBoolean 取反 |
| JavaScript | `void_return` 18.1/18.2 | 函数体末尾无 / 有 `return;` | 两者都返回 undefined |
| JavaScript | `member_access` 19.1/19.2 | `o.p` / `o["p"]` | 属性键相同；排除可选链、私有名；只替换访问记号 |
| JavaScript | `property_shorthand` 23.2/23.1 | `{a: a}` / `{a}` | 对象字面量简写定义；排除 `__proto__`（简写不设置原型）与 `undefined`；只取 `a: a` 版式 |
| JavaScript | `else_after_return` 20.2/20.1 | `if {…return}` + 余下语句 / `if {…} else {余下语句}` | 同 C；余下语句顶层无 `let`/`const`/`class`/函数声明（块作用域）；排除函数体顶层块（与 void_return 互斥） |
| JavaScript | `arrow_body` 24.1/24.2 | `x => e` / `x => { return e; }` | 箭头函数简洁体定义为返回该表达式；只取单行 `{ return e; }`；e 不以 `{` 开头、不是逗号表达式；下一记号不会被简洁体吞并 |
| JavaScript | `const_let` 25.1/25.2 | `const x = e;` / `let x = e;` | 绑定在其作用域内从未被写（按名字，保守）；单个声明符且前后无相邻声明（与 declare 互斥）；文件无 `with`/`eval` |
| JavaScript | `logical_assignment` 26.1/26.2 | `a = a \|\| b` / `a \|\|= b`（`&&`、`??` 同） | 对普通变量两者等价；a 由 let/var/形参声明且无同名 const；b 为初等表达式且不是匿名函数（`\|\|=` 会给函数命名） |
| JavaScript | `power` 27.1/27.2 | `Math.pow(a, b)` / `a ** b` | 数值上同为 Number::exponentiate；Math 未被重新绑定、文件无 BigInt；操作数初等；外层上下文白名单 |
| JavaScript | `global_alias` 28.1/28.2 | `parseInt(…)` / `Number.parseInt(…)` | 规范规定 `Number.parseInt === parseInt`（parseFloat 同）；名字未被重新绑定 |
| JavaScript | `undefined_literal` 29.1/29.2 | `undefined` / `void 0` | `void` 总得 undefined；`undefined` 未被重新绑定；不在比较操作数与成员访问对象位置 |
| JavaScript | `function_arrow` 30.2/30.1 | `m((a) => {…})` / `m(function (a) {…})` | 数组方法（map、filter、forEach、reduce、sort 等）以普通调用方式调用回调；体与默认值中无 `this`/`arguments`/`super`/`new.target`；形参无重名；只换函数头 |
| JavaScript | `empty_array` 31.1/31.2、`empty_object` 32.1/32.2 | `[]` / `new Array()`，`{}` / `new Object()` | 无参构造与空字面量都得到新的空数组/对象；`Array`/`Object` 未被重新绑定；不作成员访问或调用的对象，不在语句开头；`{}` 不在箭头函数的返回值位置 |

每种语言的水印对数：Python 25、C 21、C++ 22、JavaScript 25。

## 新增或修改规则的流程

1. 在语言模块（`cllmark/rules/python.py`、`c.py`、`cpp.py`、`javascript.py`）中以 `Matcher(pattern).where(guards...).rule(rewrite)` 定义两个方向，键为样式编号；
2. 在 [styles.json](../cllmark/rules/styles.json) 登记名称，在 `cllmark/rules/pairs.py` 末尾追加水印对（追加在末尾，不改变已有规则的槽位顺序）；
3. 运行审计，确认两个方向的适用数、自然形式（form0 应为常见形式）、幂等、可逆、语法与干扰：

```bash
.venv-benchmark/bin/python tools/rule_audit.py --language python --pairs NEW_PAIR
```

4. 在 `tests/test_rule_engine.py` 增加正反示例，执行 `make smoke` 与 `make benchmark`。

审计是结构性质检查，不能证明语义保持；语义依据写在规则文档字符串与上表中，并由 MBXP/项目测试在功能层面验证。
