# 方案：放宽 C/C++ `declare` 合并守卫（阶段 C 门禁修复）

## v1

### 目标与范围

阶段 C 全量（`20261005T184009696291Z_e2dc5610_eff2aaf0`）中，58 个原可嵌入单元失去容量，其中 43 个来自 `declare` 6.2（`merge_declarations`）。本方案只修改 C/C++ 共用的 6.2 合并守卫 `movable_group`（`c/rules.py:545`），在不重新引入语义改变的前提下恢复容量。

不在本方案范围：`while_to_for`、`for_OOO` 守卫（各 8、6 个单元，属于修复真实语义错误，保持不变）；mbpp_human FPR（Python，本改动不影响，另行分析）；JavaScript `merge_declarations`。

属于**方法协议改动**（规则适用范围变化，预期改变容量与嵌入结果）；没有工程层面的重构。

### 根因及证据

`movable_group` 把后面的同类型声明 D 上移到组内第一条声明处。现行条件：
1. D 声明的名字不出现在被跨越区域 R（第一条声明结束到 D 开始之间的源码）中；
2. D 的**所有**声明符都必须带初始值且为常量（`CONSTANT`）。

条件 2 过严：`int a; int b;`（无初始值）、`int n = 0; int m = n;`、`int i = 0; double x; int j = i + 1;` 这些 R 中只有声明、不含任何写操作或控制流的情况都被拒绝。另外条件 2 写成 `value is not None and ...`，导致**无初始值的声明符**也被拒绝，这正是函数体片段（MBCPP）里最常见的 `int i; ... int j;` 形式。

### 改动（只改 `c/rules.py`）

新增常量与辅助函数，放在 `CONSTANT` 定义之后：

```python
SIDE_EFFECTS = ['call_expression', 'assignment_expression', 'update_expression', 'new_expression',
                'delete_expression', 'co_await_expression', 'throw_expression', 'lambda_expression']
SCALAR_TYPES = ['primitive_type', 'sized_type_specifier']
```

1. `declarator_parts(declaration)`：返回 `(names, expressions)`。
   - 对 `declaration.children[1:-1]` 中每个非 `,` 子节点 c：若 `c.type == 'init_declarator'`，声明符为 `c.child_by_field_name('declarator')`，值为 `c.child_by_field_name('value')`；否则声明符为 c、值为 None。
   - names：对声明符调用 `contain_id`（与现行一致）。
   - expressions：所有非 None 的值节点，加上声明符子树中所有 `array_declarator` 的 `size` 字段节点（VLA 尺寸也会在声明处求值）。
2. `is_constant(node)`：`node.type in CONSTANT`，或 `node.type == 'initializer_list'` 且所有命名子节点递归 `is_constant`，或 `unary_expression` 且操作数 `is_constant`（覆盖 `-1`）。
3. `is_pure(node)`：子树中不含 `SIDE_EFFECTS` 中任何类型的节点，且不是 `argument_list`（C++ 构造调用 `T x(a)`）。
4. `scalar_declaration(declaration)`：`declaration.child_by_field_name('type').type in SCALAR_TYPES`。
5. `referenced_ids(nodes)`：对每个节点 `contain_id` 收集标识符。

改写 `movable_group(block, group)`：保留函数签名与返回值语义（返回保留的声明列表，第一条始终保留）。对 group[1:] 中每个 D：

- `R_nodes` = `block.children` 中满足 `first.end_byte <= n.start_byte and n.end_byte <= D.start_byte` 的子节点；`between` 文本计算方式保持现状。
- 条件 A（现有）：D 声明的名字均不以 `\b…\b` 出现在 `between` 中。
- 若 D 的 expressions 全部 `is_constant`（无 expressions 也算），只需条件 A → 保留。**（这修正了无初始值声明被拒绝的问题，行为与旧条件 2 对“全常量”的情形相同。）**
- 否则还需同时满足：
  - B1：`R_nodes` 中每个节点类型属于 `declaration` 或 `comment`（任何其他语句、预处理指令、标签、控制流都拒绝）。
  - B2：`R_nodes` 中每条声明 `scalar_declaration` 为真，且其所有 expressions `is_pure`。
  - B3：`referenced_ids(D 的 expressions)` 中的任一名字都不以 `\b…\b` 出现在 `between` 中。
  - B4：D 是 `scalar_declaration`。
  - B5：若 D 的某个 expression 非 `is_pure`，则 R 中所有声明的 expressions 必须全部 `is_constant`（避免两个有副作用/读全局的初始化交换顺序）。

`merge_declarations` 不改。

### 测试（`tests/test_rule_engine.py`）

在 `GoldenRewriteTests.CASES["c"]` 追加（期望输出以实现后实际输出为准，但必须先确认其语义正确再写入）：
- 6.2 无初始值、中间有语句：`"void f(){\n    int a;\n    g();\n    int b;\n}"` → 合并（b 名不在 R 中）。
- 6.2 非常量初始值、中间只有声明：`"void f(int n){\n    int a = n;\n    double x;\n    int b = a + 1;\n}"` → 合并为 `int a, b` 形式。

新增 `class DeclarationMergeGuardTests(unittest.TestCase)`，对 C 与 C++ 各断言 `SCTS(lang).change_file_style('6.2', code)[0] == code`（不改变）的用例：
- `test_rejects_hoisting_over_writes`：`int a = 0;\n x = 5;\n int b = x;`（B1/B3）
- `test_rejects_hoisting_over_control_flow`：`int a = 0;\n if (n == 0) return 0;\n int b = s / n;`（B1）
- `test_rejects_reordering_two_calls`：`int a = 0;\n int t = f();\n int b = g();`，其中 t 为 int（B5；注意 t 与 a/b 同类型时会进入同组，用 `long t = f();` 让它成为异类型 R 声明）
- `test_rejects_name_used_between`：`int a;\n b = 1;\n int b;`（条件 A）
- `test_rejects_class_type`（仅 C++）：`int a = 0;\n std::string s;\n int b = k;` 合并不应跨越非标量声明 → 不变（B2）

所有代码片段包在函数体中，缩进 4 空格。

### 统计（写到 scratch，不入库）

写脚本 `/tmp/claude-0/-home-user-CLLMark-legacy/80b9c75d-2ecb-5ef2-b267-4168de6c4042/scratchpad/declare_audit.py`（用 `-I` 运行不需要，直接 `.venv-benchmark/bin/python`），对 `benchmarks/config.json` 中全部 C/C++ 组的语料文件，统计 6.2 “是否改变代码”在三种守卫下的文件数：(i) 仅条件 A；(ii) 现行守卫（`git stash` 前的实现，可在脚本内复制旧函数）；(iii) 新守卫；并统计新守卫输出的语法错误数（`scts.check_syntax`）。结果写入同目录 `declare_audit.json`，回报中只给汇总数字。

### 验收标准

- `make test`（`.venv-benchmark`）全部通过；新增测试全部通过。
- `tools/rule_audit.py` 对 C/C++ 6.2：幂等/可逆失败、语法回退不多于修改前（实现者回报前后数字）。
- 审计：新守卫改变代码的文件数 > 现行守卫，且新守卫下语法错误数不多于现行守卫。
- 全量（由 bench-runner 执行，不由实现者执行）对照云端修复前参考：功能回退 0 新增、框架错误 0、`declare` 相关丢失单元减少。

### 禁止事项

- 不修改 `while_to_for`/`for_OOO`/其他规则，不修改 `rule_engine.py`、度量、配置、语料、基线。
- 不放宽条件 A；不允许跨越含控制流或写操作的语句上移非常量初始值。
- 不删除或跳过任何测试。
- 不提交（commit 由主会话执行）。

## v2

v1 实现评审结论：

- **接受偏离**：已保留（kept）的声明与 D 一起按原顺序上移，不计入 B1–B5 的跨越区域 R；B3 的名字检查只在剩余 R 节点的文本上进行。理由：相对顺序不变，不构成跨越；字面 v1 使幂等失败从 C 44→167、C++ 23→48。
- **可逆性验收改为比率**：`rev.fail` 绝对数随可适用位置增加而增加，不再要求“不多于修改前”；由全量的可逆率判断（不得低于修复前参考 1 个百分点以上）。

v2 修改（只改 `c/rules.py` 与 `tests/test_rule_engine.py`）：

1. `referenced_ids` 不再调用 `contain_id`（它跳过父节点为 `subscript_expression`/`call_expression` 的标识符，会漏掉 `a[i]` 中的 `a`）。改为遍历子树收集所有 `identifier` 节点文本（不含 `field_identifier`）。`declarator_parts` 的 names 仍用 `contain_id`，保持条件 A 现状。
2. 新增测试 `test_rejects_reading_array_declared_between`（C 与 C++）：`int i = 0;\n int a[3] = {1, 2, 3};\n int b = a[i];`（注意 a 与 i/b 同为 int，会与 i 同组——改用 `long a[3] = {1, 2, 3};` 使其成为 R 中异类型声明），期望 6.2 合并时 b 不被上移。
3. 新增测试 `test_rejects_reordering_effect_past_global_read`（C 与 C++）：`int a = 0;\n long t = g;\n int b = f();`，R 中无调用，由 B5 拒绝，期望不变。

验收：`make test` 全部通过；重跑 `declare_audit.json` 与 rule_audit 的 C/C++ 数字并回报。
