# JavaScript 规则扩充与审计方案

## v1

### 1. 目标与范围

- JavaScript 目前 15 个水印规则对（`rule_dict_bit_acc.py`），Python 25、C 21、C++ 22。新增 7 个语义保持的双向规则对，使 JavaScript 达到 22 个，并对全部 JavaScript 规则对做全量审计、修复审计发现的问题。
- 不改 Python/C/C++ 规则，不改度量、门禁、语料、`benchmarks/`（除非审计脚本本身对 JavaScript 有缺陷，此时只修脚本并在回复中说明）。
- 属于方法改动（JavaScript 规则集合），与阶段 D 一起在新协议 `cllmark-3` 下测量。

### 2. 现状（主会话已完成）

- tree-sitter-javascript v0.20.1 已构建进 `.benchmark-cache/toolchain`，`.venv-benchmark/bin/python -m unittest discover -s tests` 48 个测试全部通过。
- Node v24（支持 `||=`、`??=`、`**`）。
- 规则写法见 `docs/RULES.md` 与 `javascript/rules.py`：查询 + 具名守卫（`@guard`）+ 锚定编辑，前置条件不满足时 `raise Reject`。比特 0 取语料中更常见的形式（未加水印代码读出全 0，降低 FPR）。
- 规则区域互斥原则：新规则在两种形式下都不能改变任何其他规则对的候选集合（"形式不变的候选性"）；与比较相关的规则一律加 `outside_equality_operands`。所有规则加 `well_formed`。

### 3. 新增规则（样式编号、名称、比特顺序由实现者按 3.8 确定）

#### 3.1 `else_after_return`（20.1 / 20.2）

`if (c) { …; return x; } else { S }` ↔ `if (c) { …; return x; } S`。移植 `c/rules.py` 中 20.1/20.2（`exiting_braced_if_then_rest`、`exiting_braced_if_else`、`exits`、`add_braced_else`、`drop_braced_else`）的全部守卫与"单站点域"约束，并补充 JavaScript 特有约束：

- 被移入或移出 else 块的语句在其顶层不得含 `lexical_declaration`（let/const）、`class_declaration`、`function_declaration`、`generator_function_declaration`（块级作用域与提升语义不同）。`variable_declaration`（var）允许。
- then 块以 `return_statement` 或 `throw_statement` 结束（与 C 的 `exits` 对应；`break`/`continue` 按 C 版本的处理方式）。
- 必须与 14.x（branch_order，花括号 if-else 交换分支）区域互斥：参照 C 版本如何避免与 C 的 14.x 干扰，并用审计确认干扰为 0。

#### 3.2 `arrow_body`（24.1 / 24.2）

`(p) => e` ↔ `(p) => { return e; }`。

- 转为块体：箭头函数 `body` 不是 `statement_block`。输出 `{ return e; }`，`e` 原样保留（若 `e` 是 `parenthesized_expression` 包裹的对象字面量，保留括号以保证可逆）。
- 转为简洁体：`body` 是只含一条 `return_statement` 且有返回值的 `statement_block`，块内无注释。若返回值是 `object` 或 `sequence_expression`，加括号输出；其余原样。
- 两个方向的输出格式要固定（单行 `{ return e; }`），保证幂等与可逆；多行块体仍可转为简洁体，但反向生成单行——若这会让可逆检查失败，只接受单行块体 `{ return e; }`，并在回复中说明选择。
- 确认与 18.x（void_return，匹配 `arrow_function`）互不干扰：块体 `{ return e; }` 以非空 return 结尾，18.1/18.2 都不应匹配。

#### 3.3 `const_let`（25.1 / 25.2）

`const x = e;` ↔ `let x = e;`，仅当绑定从不被写入。

- 匹配父节点为 `program`、`statement_block`、`switch_case`/`switch_default` 的 `lexical_declaration`（不在 for 头部）；每个声明符都有初始值。
- 声明的所有名字（含解构模式中的标识符）在其作用域（父节点子树，保守地取整个父节点）中不作为下列目标出现：`assignment_expression` 的 `left`（含解构赋值模式内的标识符）、`augmented_assignment_expression` 的 `left`、`update_expression` 的参数、`for_in_statement` 的左侧裸标识符。按名字匹配，不做遮蔽分析（保守）。
- 与 6.x（declare）区域互斥：只匹配前后相邻兄弟都不是 `lexical_declaration`/`variable_declaration` 的声明（6.2 只合并相邻同关键字声明，6.1 只看声明符数量，不受关键字影响）。用审计确认干扰为 0。

#### 3.4 `logical_assignment`（26.1 / 26.2）

`a = a || b` ↔ `a ||= b`，同样适用于 `&&`、`??`。

- `a` 为 `identifier`，且在同一文件中由 `let`/`var` 声明符或函数形参声明过；文件中没有名为 `a` 的 `const` 声明。（`a ||= b` 在 `a` 为真值时不执行赋值；对普通变量这与 `a = a` 等价；对 const 原形式总会抛错，因此排除。）
- `b` 的形式限制同 2.1 的 `OPERAND`；若 `b` 本身是 `||`/`&&`/`??` 或更低优先级表达式，正向生成 `a ||= (b)` 会破坏可逆，因此不匹配。
- 不与 2.1/2.2 干扰：`compound_assignment` 的运算符集合 `COMPOUND` 不含 `||`/`&&`/`??`（已确认），审计复核。

#### 3.5 `power`（27.1 / 27.2）

`Math.pow(a, b)` ↔ `a ** b`。

- 文件中没有名为 `Math` 的绑定（声明符、形参、函数/类声明、import）。文件中出现 BigInt 字面量（`number` 文本以 `n` 结尾）或 `BigInt` 标识符时整个文件不匹配（`Math.pow` 对 BigInt 抛错）。
- 两侧操作数都必须是"初等"节点：`identifier`、`number`、`member_expression`、`subscript_expression`、`call_expression`、`parenthesized_expression`。不加也不去除任何括号，以保证可逆。
- 外层：`Math.pow(...)` 调用或 `**` 表达式的父节点不得是 `unary_expression`、`update_expression`、`await_expression`、`member_expression`（作为 object）、`subscript_expression`（作为 object）、`call_expression`（作为 function）、运算符为 `**` 的 `binary_expression`；也不得是 `assignment_expression`/`augmented_assignment_expression` 的右侧（避免 `a = Math.pow(a, b)` → `a = a ** b` 新增 2.1 候选）。
- `Math.pow` 调用：恰好两个实参，无展开。

#### 3.6 `global_alias`（28.1 / 28.2）

`parseInt(...)` ↔ `Number.parseInt(...)`，`parseFloat` 同理（规范规定 `Number.parseInt === parseInt`）。

- 文件中没有名为 `parseInt`/`parseFloat`/`Number` 的绑定。
- 只匹配作为 `call_expression` 的 `function` 出现的标识符或 `Number.parseX` 点访问。
- 与 19.x（member_access）互斥：修改 `javascript/rules.py` 中 19.2 的 `dot_access`，排除对象为 `Number` 且属性为 `parseInt`/`parseFloat` 的点访问（19.1 对应的方括号形式不会由本规则产生）。这一修改减少 19.2 的候选，属于 JavaScript 新规则内部调整，可接受。

#### 3.7 `undefined_literal`（29.1 / 29.2）

`undefined` ↔ `void 0`。

- 文件中没有名为 `undefined` 的绑定。只匹配表达式位置的 `undefined` 节点（不作属性名、不作声明符名、不作形参）；`void 0` 方向只匹配 `unary_expression` 运算符 `void`、操作数为 `number` 文本 `0`。
- 两个方向都加 `outside_equality_operands`（`SIMPLE` 含 `undefined`，比较中的替换会改变 2.11–2.14 候选）。
- 父节点为 `member_expression`/`subscript_expression`/`call_expression`（作为 object/function）时不匹配。

#### 3.8 编号、注册与比特顺序

- 在 `javascript/rules.py` 的 `RULES` 中按上述编号注册；`styleList.json` 的 `javascript` 段增加对应说明；`rule_dict_bit_acc.py` 的 `javascript` 段增加 7 个规则对。
- 比特顺序：对 `dataset/MBJSP_H`、`dataset/MBJSP_G`、`.benchmark-cache/js-projects` 中的 JavaScript 文件，统计每个规则对两种形式的候选数（`get_file_popularity` 或 `Parsed.candidates`），**比特 0 = 更常见的形式**（即列表第一个样式是把代码改成"罕见形式"的那个——先读现有条目确认列表约定，例如 `'declare': ['6.1', '6.2']` 的含义，再按相同约定写）。统计表写入 `docs/plans/2026-10-06-javascript-rules.forms.tsv`。
- 若某个规则在全部 JavaScript 语料中两种形式的候选总数 < 5，仍保留实现与测试，但在回复中标出。

### 4. 审计与修复（包括原有 15 个规则对）

1. 对 JavaScript 全部规则对运行：
   `.venv-benchmark/bin/python tools/rule_audit.py --language javascript --against all --output docs/plans/2026-10-06-javascript-rules.audit.txt`
   先在新增规则前运行一次（`…audit-before.txt`），完成后再运行一次。
2. 验收：每个规则对的语法回退 = 0、与其他规则对的干扰 = 0；幂等与可逆失败各 ≤ 该规则 applicable 的 1%（并列出剩余失败的前 3 个原因）。原有 15 个规则对若审计发现问题，按同一标准修复（加守卫，不删规则）。
3. 功能抽检：写只读脚本 `tools/js_rule_check.py`，对 `dataset/MBJSP_H` 中每个可应用某规则的问题，用该规则改写后执行 Node 测试（复用 `benchmarks/utility.py` 的 JavaScript MBXP oracle 实现，不要另写一套），统计"原解通过而改写后失败"的数量；验收为 0。结果写入 `docs/plans/2026-10-06-javascript-rules.functional.tsv`。

### 5. 测试

- `tests/test_rule_engine.py` 的 `GoldenRewriteTests.CASES["javascript"]` 中，每个新样式至少一个正例和一个反例（触发守卫、输出不变），覆盖：else 块含 `let`（拒绝）、`x => ({a: 1})`、`x => (a, b)`、被重新赋值的 `const` 候选（拒绝）、`const a = 1;` 与相邻声明（拒绝）、`a = a || b` 中 `a` 为 const（拒绝）、文件含 BigInt 时的 `Math.pow`（拒绝）、`let Math = …` 遮蔽（拒绝）、比较中的 `undefined`（拒绝）。
- `test_style_catalog_rules_and_watermark_pairs_agree` 必须通过。
- 全部测试：`.venv-benchmark/bin/python -m unittest discover -s tests -v` 通过。

### 6. 工作位置与交付

- 在隔离 git worktree 中工作。开始时在 worktree 根目录建立：
  `ln -s /Users/bytedance/Downloads/data/data/.venv-benchmark .venv-benchmark`
  `ln -s /Users/bytedance/Downloads/data/data/.claude/worktrees/admiring-merkle-4012a5/.benchmark-cache .benchmark-cache`
  不要建立 `build` 链接，不要修改 `.benchmark-cache/toolchain`。
- `dataset/` 是 git 跟踪的原始语料，只读。
- 完成后在该 worktree 分支上提交一次 commit（规则、注册、styleList、测试、两个工具脚本与 `docs/plans/` 下的输出），回复分支名与提交 SHA。不要推送，不要运行 `make benchmark`。
- 回复格式（≤ 30 行）：每个新规则一行（编号、比特 0 形式、两种形式候选数、审计 幂等/可逆/语法/干扰）；原有规则修复列表；功能抽检结果；偏离方案之处；待决问题。

## v1 补充（冒烟结果之后，主会话；与上文冲突时以本节为准）

冒烟记录见 `docs/plans/2026-10-06-js-smoke.notes.md`。

### S1. 修复 js-yaml 上的可逆失败（原有规则）

js-yaml 的性质探测中可逆失败 14/272：declare 8、reverse_compare 2、equal_to_not_equal 2、not_equal_to_equal 1、equal_hash_reverse 1（文件 loader.js、int.js、binary.js、snippet.js 等，路径 `.benchmark-cache/js-projects/js-yaml/lib/`）。审计（第 4 节）必须把 `.benchmark-cache/js-projects/*`（排除 node_modules、test、dist）纳入审计语料；逐个查明原因并加守卫或修正改写，使这些文件上可逆失败为 0，或在回复中逐个说明为何无法做到。

### S2. MBJSP 容量是首要目标

冒烟中 MBJSP 只有约 1% 单元可嵌入（需要 7 个码位），mbjsp_human 60 个中 0 个。新增规则与修复完成后，用 `watermark_core.analyze`（或 `folder_transform_check.check_support_transform` 的同等逻辑，不写语料目录）统计 `dataset/MBJSP_H` 与 `dataset/MBJSP_G` 每个单元的容量分布（前后对比），以及每个规则对在 MBJSP 上的可应用单元数，写入 `docs/plans/2026-10-06-javascript-rules.capacity.tsv`，回复中给出：容量 ≥ 7 的单元数（前/后）、贡献最大的 5 个规则对。
若新增 7 个规则后 MBJSP 可嵌入比例仍低于 5%，在"待决问题"中列出你在语料中观察到的、出现频率最高且可做成语义保持双向规则的 3 种代码形式（附出现次数和等价性论证），不要自行实现。

### S3. 项目测试日志位置（工程改动，允许修改 `benchmarks/utility.py`）

`benchmarks/utility.py` 约 221 行项目测试以 `cwd=cache/project` 运行，`test-attempt-*.stdout/stderr` 写在 `cache/project/` 下，而约 108 行 `evaluate_utility` 只收集缓存根目录的日志，导致 js_projects 单元 `.utility/` 中只有 result.json。修正为把日志写到缓存根目录（或收集时包含 project 子目录），使每单元目录中保留失败证据；增加/调整对应测试。该改动改变 utility.py 摘要（缓存键与协议指纹），由于 cllmark-3 尚无参考运行，可以接受。

## v2（主会话审查 `3311ba7f` 后）

v1 已合并进 `claude/admiring-merkle-4012a5`（`8246e38d`）。MBJSP 可嵌入仍为 1.1%。采纳待决问题中的 2 与 3，拒绝 1（单语句体加/去花括号只改变语法外形，不涉及语义变换，属于目标明确禁止的格式类改写）。

### V1. `function_arrow`（30.1 / 30.2）

`recv.m(function (p) { … })` ↔ `recv.m((p) => { … })`。

- 只匹配作为 `call_expression` 实参、且被调方是 `member_expression`、属性名属于 `map filter forEach reduce reduceRight some every find findIndex findLast findLastIndex flatMap sort` 的回调（这些方法以普通调用方式调用回调，从不 `new`，也不读取 `prototype`）。
- function 方向：匿名 `function`（不是 `generator_function`，没有名字），`async` 保留为 `async (p) => {…}`。
- 函数体（包括嵌套的箭头函数，不包括嵌套的普通函数、方法、类）中不出现 `this`、`arguments`、`super`、`new.target`；形参默认值中同样不出现。
- 与 24.x 区域互斥：两种形式的函数体都不能是单行 `{ return e; }`（否则箭头形式会成为 24.1 候选）。与 18.x：FUNCTIONS 同时匹配两种形式，候选性不变，审计复核。
- 输出格式固定：`function (a, b) {` ↔ `(a, b) => {`（单个形参也加括号），函数体文本原样保留，保证可逆。只接受与对方写法一致的布局。

### V2. `empty_array`（31.1 / 31.2）与 `empty_object`（32.1 / 32.2）

`[]` ↔ `new Array()`；`{}` ↔ `new Object()`。

- 文件中没有名为 `Array` / `Object` 的绑定。
- 只匹配表达式位置、无元素的 `array` / 无属性且无注释的 `object`，以及无实参的 `new_expression`（`new Array()`，括号必须存在；`new Array` 无括号不匹配）。
- 不匹配：作为 `member_expression`/`subscript_expression`/`call_expression` 的对象或函数的（`[].concat`、`new Array().fill` 的优先级不同）；箭头函数简洁体 `() => ({})` 内的；解构模式中的。
- 与 23.x、19.x、6.x 等审计复核干扰为 0。

### V3. 其他

- `property_shorthand` 的比特顺序改为常见形式为比特 0（`forms.tsv` 中 2 vs 7）。
- 更新 `docs/RULES.md` 的 JavaScript 部分（规则数、每个新规则一行，按现有体例）。
- 比特顺序按 3.8 的原则统计；重跑全部 JavaScript 审计（含 js-projects 与扩展审计）、功能抽检与容量统计（S2 表，给出 v1 → v2 的可嵌入单元数）。

验收同 v1：所有规则对幂等/可逆/语法/干扰为 0，功能抽检 0 回退，测试全部通过。每个新规则至少一个正例与一个反例（含 `this` 的回调、`new Array(3)`、`[].length`、`() => ({})`、`let Array = …`）。在同一分支追加提交。

## v3（真实语料接入后，主会话）

语料扩充已合并（`6739d266`）：`js_repos`（14 个仓库）、`js_repo_files`（84 个文件单元）、`exercism_js`（100 题），源码在 `dataset/JS_repos/`、Exercism 相关文件见 `benchmarks/config.json` 与 `docs/plans/2026-10-06-javascript-corpus.selection.md`。这些语料取代 MBJSP 成为 JavaScript 的主要证据。

### T1. 比特顺序按真实语料重定

- 对 `dataset/JS_repos/`（全部被测源文件）与 Exercism 参考解统计全部 25 个规则对两种形式的候选数（与 v1 3.8 同口径；MBJSP 单独列出但不参与决定），**比特 0 = 真实语料中更常见的形式**。写入 `docs/plans/2026-10-06-javascript-rules.forms-real.tsv`，并在回复中列出改变了顺序的规则对。
- 只改 `rule_dict_bit_acc.py` 的 JavaScript 段顺序。

### T2. 在真实语料上审计与功能检查

- `tools/rule_audit.py --language javascript --against all` 覆盖 `dataset/JS_repos/` 与 Exercism 参考解（若审计脚本的语料来源需要扩展，扩展脚本并说明），验收：幂等/可逆/语法/干扰全部为 0；不为 0 的逐个查明并以守卫修复（不放宽语义约束）。
- 功能检查：扩展 `tools/js_rule_check.py`，对每个仓库与每道 Exercism 题，逐规则（单独应用每个规则对的两个方向，在所有可应用位置）改写后运行该仓库/该题的测试，统计"干净通过而改写后失败"。已知例外：`ejs/lib/utils.js` 的测试比较函数源码文本（`escapeXML.toString()`），任何改写该函数的规则都会使其失败——这是测试读取源码文本，不是语义变化；单独列出这类情况，不为它加守卫。其他失败均视为语义问题，必须修复。结果写入 `docs/plans/2026-10-06-javascript-rules.functional-real.tsv`。

### T3. 单元超时

- `lodash.js` 单元在负载下需 92–157 s，接近 `unit_timeout_seconds` 180。为 cohort 增加可选的 `unit_timeout_seconds` 覆盖（`benchmarks/config.json` 中 `js_repos`、`js_repo_files` 设为 600），实现于 runner/engine 中现有超时处的最小改动，并加测试。先用 profiler 或计时确认 lodash 单元时间主要花在哪里（解析、性质探测、测试套件），若某处有明显的重复计算，在回复中指出（不要顺手大改）。

验收：测试全部通过；在同一分支提交；回复 ≤ 30 行（改变顺序的规则对、审计结果、功能检查结果与修复、超时实现与 lodash 时间分布、偏离、待决问题）。
