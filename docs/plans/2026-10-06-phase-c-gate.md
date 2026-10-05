# 阶段 C 门禁失败修复方案

失败运行：`20261005T184009696291Z_e2dc5610_eff2aaf0`（源码 `eff2aaf0…`），基线 B0 `20261005T160717720996Z_e2dc5610_6e2e98ae`。
运行目录：`/Users/bytedance/Downloads/data/data/.claude/worktrees/admiring-merkle-4012a5/benchmark-results/`。

## v1

### 1. 目标与范围

- 消除 `declare` 6.2 与 `while_to_for` 7.8 守卫中“拒绝了本来安全的位置”的部分，恢复失去容量的单元，且不重新引入阶段 C 修掉的不安全改写。
- 对其余失去容量的单元逐个给出拒绝原因，供主会话判定是否属于真实的安全拒绝。
- FPR 不做代码改动（见 2.3）。
- 不改 Python 规则、不改新增规则对、不改度量与门禁、不改语料。

### 2. 根因及证据

#### 2.1 失去容量的 58 个单元

- 全部是边缘单元：B0 中容量恰好等于需求 7 的 57 个、余量 1 的 1 个；本次各缺 1–2 个槽位。
- 按规则：`declare` 43、`while_to_for` 8、`for_OOO` 6、`self_assignment` 2、`update_reverse` 2（单元可重叠）。
- 按组：cpp_snippets 18、mbcpp_generated 9、mbcpp_generated_subset 9、c_generated 8、codenet_generated 6、mbcpp_human 4、codenet_human 3、c_historical_marked 1。`utility.lost_paired_ids` 的 22 个 MBCPP 单元是同一批单元失去资格的连带结果。

#### 2.2 守卫过严之处

- `c/rules.py:545` `movable_group`：每个后续声明都要求初始值是 `CONSTANT` 字面量，**即使它与首个声明之间没有任何语句**。相邻声明 `int n = v.size(); int i = 0;` 也不能合并，而 `int n = v.size(), i = 0;` 是等价的：C 的每个完整声明符结束处有序列点，C++ 的每个 init-declarator 按顺序初始化，就像分别声明一样。
- `c/rules.py:814-815` `while_to_for`：计数更新不是循环体最后一条语句或循环含 `continue` 时，直接 `Reject` 整个改写。真正不安全的只是“把更新移进 for 头部”；`while(b) S` → `for(MARKER; b; ) S`（更新留在体内）始终等价。重写函数已支持 `update is None`（空的第三子句），其逆向规则（样式 12）也已支持这种形式。
- `for_OOO`、`self_assignment`、`update_reverse` 的拒绝条件（`continue` 跳过移到末尾的更新、无花括号循环体、下标/调用/赋值内的自增）都是真实的语义风险，v1 不放宽，只做 4.2 的审计。

#### 2.3 FPR（mbpp_human 0/41 → 2/72）

- 消息为 4 比特，采用 BCH(7,4)、纠 1 位：任意 7 比特读数译成给定消息的机会概率是 8/128 = 1/16。
- 两个假阳性 MBPP_415、MBPP_850 都是**新增的可嵌入单元**（在 B0 中不可嵌入），且都是纠 1 位后匹配（`raw_matched` 为假）。B0 原有的 41 个负样本在本次中假阳性仍为 0。
- 在机会水平 1/16 下：B0 41 个全为阴性的概率为 7.1%；72 个中不超过 2 个的概率为 16.5%。观测值低于机会期望 4.5。
- 在约 72 个样本时，1 个假阳性就是 1.39 个百分点，“FPR 增幅 ≤ 1 个百分点”的门禁对任何处于机会水平的方法都无法稳定满足。这是评估协议的统计效力问题，不是规则缺陷。改门禁或改 FPR 计算属于协议改动，需要用户决定，v1 不做。为降低 FPR 而针对这两个样本调整规则属于过拟合，禁止。

### 3. 改动（仅 `c/rules.py`，C++ 通过 `c_family_rules` 共享）

#### 3.1 `movable_group(block, group)` 重写判定（`c/rules.py:545`）

对 `group[1:]` 中的每个后续声明 D，按 `block.children` 中位于 `first` 与 D 之间的子节点逐个分类：
- `comment` → 忽略；
- 已放入 `kept` 的声明 → 忽略（合并后仍在 D 之前，顺序不变）；
- 其他任何节点（包括未被保留的同类声明和其他类型的声明）→ “被跨越节点”。

D 被保留须同时满足：
1. （保留现有条件）D 声明的名字不以整词形式出现在任何被跨越节点的文本中。
2. 若没有被跨越节点：不限制初始值。
3. 若有被跨越节点，D 的每个 `init_declarator` 都必须有 `value` 且满足：
   a. value 子树中的每个**具名节点**类型都属于 `HOISTABLE = ['identifier', 'number_literal', 'char_literal', 'string_literal', 'string_content', 'escape_sequence', 'true', 'false', 'null', 'nullptr', 'parenthesized_expression', 'unary_expression', 'binary_expression', 'cast_expression', 'type_descriptor', 'primitive_type', 'sized_type_specifier', 'sizeof_expression', 'concatenated_string']`；
   b. 每个 `unary_expression` 的运算符属于 `-`、`+`、`!`、`~`；每个 `binary_expression` 的运算符属于 `+`、`-`、`*`、`<`、`>`、`<=`、`>=`、`==`、`!=`、`&&`、`||`、`&`、`|`、`^`（不含 `/`、`%`、`<<`、`>>`）；
   c. 若 value 中含 `identifier`：value 中的每个标识符都不以整词形式出现在被跨越节点中；被跨越节点子树中不能有 `call_expression`；也不能有左操作数（`assignment_expression` 的 `left` 字段或 `update_expression` 的操作数）为 `pointer_expression`、`subscript_expression` 或 `field_expression` 的写入。
4. 若被跨越节点存在且 `block.type != 'compound_statement'`（例如 ERROR 或 translation_unit 片段）：只允许走第 2 条（即只合并没有被跨越节点的声明）。
5. 原有 `CONSTANT` 常量保留，以便第 3 条中的字面量判断复用；`CONSTANT` 中的类型都包含在 `HOISTABLE` 中。

#### 3.2 `merge_declarations`（`c/rules.py:561`）增加类型拒绝

- 当 `kind` 以整词形式包含 `auto` 或 `decltype` 时跳过该组（C++ 中 `auto a = 1; auto b = 2.0;` 合并后无法通过编译；放宽后相邻声明更容易触发这一问题）。直接 `continue`，不要 `Reject` 整个节点。

#### 3.3 `while_to_for` 回退（`c/rules.py:814-815`）

- 把
  `if update is not None and (update 不是最后一条非注释语句 or loop_continues(...)): raise Reject(...)`
  改为在同样条件下令 `update = None`（更新保留在循环体内，头部第三子句为空），继续生成改写。
- 文档字符串相应更新为：“只有当更新是最后一条语句且没有 continue 跳过它时，才把它移进头部；否则保留在循环体内，头部第三子句为空。”
- 其余拒绝（do-while、已是 for、条件无标识符、标记名已被使用）不变。

#### 3.4 测试（`tests/test_rule_engine.py` 中 `GoldenRewriteTests.CASES`）

在 `"c"` 中增加以下用例，期望输出以实现后的实际输出为准，但必须满足括号中的语义要求，并把实际字符串固定进测试：
- `6.2` 相邻非常量初始值：`"void f(int n){\n    int a = n + 1;\n    int b = g(a);\n}"` →（合并为一条 `int a = n + 1, b = g(a);`，顺序不变）。
- `6.2` 跨越语句且初始值读取被写入的变量：`"void f(int n){\n    int a = 0;\n    n = n + 1;\n    int b = n;\n}"` →（不合并，输出与输入相同）。
- `6.2` 跨越含调用的语句：`"void f(int n){\n    int a = 0;\n    g();\n    int b = n;\n}"` →（不合并）。
- `6.2` 跨越语句且初始值为纯表达式、标识符未被涉及：`"void f(int n){\n    int a = 0;\n    a = 1;\n    int b = n * 2;\n}"` →（合并为 `int a = 0, b = n * 2;`，`a = 1;` 仍在其后）。
- `7.8` 更新不在末尾：`"void f(int n){\n    int i = 0;\n    while (i < n) {\n        i++;\n        g(i);\n    }\n}"` →（得到带标记且第三子句为空的 for，`i++;` 仍在 `g(i);` 之前）。
- `12` 对上一条输出再应用，恢复为原输入（逐字节相同；若只有空白差异，在“偏离方案之处”中报告，不要改规则去迁就）。

在 `"cpp"` 中增加：
- `6.2` `"void f(){\n    auto a = 1;\n    auto b = 2.0;\n}"` →（不合并）。

### 4. 实现者需产出的数据

#### 4.1 规则审计（改动前后各一次，同一份代码基准）

在本工作树中，改动前先运行（将输出保存为 `docs/plans/2026-10-06-phase-c-gate.audit-before.<lang>.txt`），改动后再运行（`…audit-after.<lang>.txt`），`<lang>` 为 `c` 和 `cpp`：

```
/Users/bytedance/Downloads/data/data/.venv-benchmark/bin/python tools/rule_audit.py --language <lang> --pairs declare while_to_for --against all --output <文件>
```

回复中给出每种语言、每个规则对的前后数字：applicable、幂等失败、可逆失败、语法回退、干扰。

#### 4.2 失去容量单元的逐槽位原因

编写 `tools/lost_capacity_report.py`（只读，不写运行目录），输入为两个 `rows.jsonl`（B0 与候选运行）以及可选的源码根目录。对每个“B0 可嵌入、候选不可嵌入”的单元，以及该单元在 B0 的 `embedding_slots` 中多于候选的每个规则：在当前代码上对该单元的源文件调用相应样式，用 `Rule.explain` 或捕获 `Reject` 得到拒绝原因；如果当前代码已经接受该槽位，记为 `recovered`。输出 TSV：`unit_id  cohort  rule  style  outcome(recovered|rejected)  reason  first_line_of_matched_node`。
对阶段 C 失败运行执行一次，结果写到 `docs/plans/2026-10-06-phase-c-gate.lost-v1.tsv`。回复中给出：按 rule × outcome 的计数、可恢复单元数（该单元的所有缺失槽位都已 `recovered` 且容量 ≥ 7）。

#### 4.3 补丁

测试通过后，运行 `git diff -- c/rules.py tests/test_rule_engine.py > docs/plans/2026-10-06-phase-c-gate.v1.patch`，供第 6 节使用。`tools/lost_capacity_report.py` 必须支持 `--source-root`，以便在 eval 检出的代码上解释拒绝原因（脚本本身不进补丁）。不要提交 git commit。

### 5. 验收标准

实现（implementer，在本工作树）：
- `/Users/bytedance/Downloads/data/data/.venv-benchmark/bin/python -m unittest discover -s tests -v`：除已知的 JavaScript 语法库相关 2 个报错、4 个跳过外全部通过；新增 golden 用例全部通过。
- 审计：`declare`、`while_to_for` 在 C/C++ 中的语法回退与干扰均为 0；幂等/可逆失败数不高于改动前；applicable 不低于改动前。
- 4.2 表中 `declare` 与 `while_to_for` 行的大多数为 `recovered`；若 `declare` recovered 少于 30 行，在回复中列出出现最多的 3 种拒绝原因。

全量实验（bench-runner，在可比检出中，见第 6 节）：
- `comparable = true`（与 B0 的数据集、协议、环境指纹一致）。
- `new_functional_regressions = 0`，`utility.retention` 保持 100%，`harness_errors = 0`。
- `syntax_retention` ≥ 99.99%；幂等/可逆/互不干扰均不低于阶段 C 失败运行（99.97% / 95.79% / 97.67%）超过 0.1 个百分点；恢复率 ≥ 99.5%。
- `lost_eligible_units` ≤ 15，`utility.lost_paired_ids` ≤ 6；剩余每个单元都在 triage 中带有 4.2 的拒绝原因。
- 预期 `lost_eligible_units` 门禁仍不能降到 0，mbpp_human FPR 门禁也可能仍未通过；这两项由主会话判定并记录，不能为了通过而修改门禁。

### 6. 可比的实验检出（bench-runner 执行）

本分支 HEAD 包含阶段 D（`protocol_version = cllmark-3`、JavaScript 语料与工具链），在 HEAD 上运行的全量结果与 B0 不可比。阶段 C 的修复要在阶段 C 快照之上测量：
1. `git -C /Users/bytedance/Downloads/data/data worktree add --detach .claude/worktrees/phase-c-eval e2dc5610`（若已存在则跳过，先确认它不是别的会话正在使用的目录）。
2. `rsync -a --delete --exclude .git --exclude benchmark-results --exclude __pycache__ /Users/bytedance/Downloads/data/data/.claude/worktrees/baseline-legacy-e2dc5610/ /Users/bytedance/Downloads/data/data/.claude/worktrees/phase-c-eval/`（来源只读，不要修改 baseline-legacy 工作树）。
3. 校验：`diff -rq <失败运行目录>/source <eval> -x .git -x dataset -x '*_func' -x benchmark-results -x .claude -x docs -x __pycache__ -x build` 中除 `Only in <eval>` 之外没有输出；`benchmarks/baselines/current.json` 的 run_id 为 B0。
4. 应用 implementer 产出的补丁 `docs/plans/2026-10-06-phase-c-gate.v1.patch`（只含 `c/rules.py` 与 `tests/test_rule_engine.py`）：`patch -p1 -d <eval> < 补丁`。测试文件块冲突时，只把冲突情况报告给主会话，不要手工改写规则。
5. 在 eval 目录下运行 `make smoke BENCH_PYTHON=/Users/bytedance/Downloads/data/data/.venv-benchmark/bin/python`，再运行 `make benchmark BENCH_PYTHON=…`。
6. 结果在 `<eval>/benchmark-results/<run_id>/`。triage.txt 中每个仍失去容量的单元附上 4.2 的原因（对新运行重新执行 `tools/lost_capacity_report.py`，输出 `<run_dir>/lost.tsv`）。

### 7. 禁止事项与改动性质

- **方法协议改动**：3.1–3.3 改变规则的适用位置，因此改变容量与嵌入结果。它们是对阶段 C 方法改动的修订，与 B0 比较时仍属于“方法改动、协议与度量不变”，结果可比。
- **工程改动**：4.2 的报告脚本、第 6 节的检出流程，不影响结果。
- 禁止：修改 `benchmarks/config.json` 中的门禁或 FPR 计算；为通过门禁而删除样本或改语料；放宽 `for_OOO`、`self_assignment`、`update_reverse` 的守卫；为这两个假阳性样本专门调整规则；运行 `tools/research_loop.py baseline`；修改 `benchmarks/baselines/`、`dataset/`、`*_func`；在 HEAD 上运行全量 benchmark 并与 B0 比较。
- 已知局限：语法通过与审计可逆只是结构证据；语义证据来自有功能 oracle 的单元（MBCP/MBCPP 等）。cpp_snippets、CodeNet 中新合并的声明没有功能测试覆盖。

## v1 主会话审查修订（优先于上文）

上文由另一会话起草，本节为审查后的修改；与上文冲突时以本节为准。

### R1. 第 3.1 条补充两项拒绝

- 若任一被跨越节点的子树中含有 `labeled_statement`、`case_statement`、`goto_statement`，则后续声明只能走"无被跨越节点"的情形（即不跨越语句上移）。原因：跳转到被跨越的标签/case 会绕过已上移的初始化；C++ 中这还是编译错误。
- D 的声明符中除被声明名字之外的标识符（例如数组长度 `int b[n]`、C++ 构造参数 `T x(n)` 中的 `n`）与初始值同等对待：有被跨越节点时，它们不得以整词形式出现在被跨越节点中；`argument_list`、`initializer_list` 不在 `HOISTABLE` 中，因此 C++ 的构造式/花括号初始化在跨越语句时会被拒绝，这是预期行为。

### R2. 工作位置（替换第 4.1、4.3、6 节的路径约定）

- 实现者在自己的隔离 git worktree 中工作（由主会话启动）。开始时在 worktree 根目录建立：
  `ln -s /Users/bytedance/Downloads/data/data/.venv-benchmark .venv-benchmark`
  `ln -s /Users/bytedance/Downloads/data/data/.claude/worktrees/admiring-merkle-4012a5/.benchmark-cache .benchmark-cache`
  不要建立 `build` 链接（解析库从 `.benchmark-cache/toolchain` 加载）。
- 审计与报告输出写到 worktree 内的 `docs/plans/` 下（文件名同上文）。完成后在该 worktree 的分支上提交一次 git commit（包含 `c/rules.py`、`tests/test_rule_engine.py`、`tools/lost_capacity_report.py` 与 `docs/plans/` 下的输出），回复中给出分支名与提交 SHA。不要推送。
- 第 6 节的可比检出已由主会话建立：`/Users/bytedance/Downloads/data/data/.claude/worktrees/phase-c-eval`（阶段 C 快照，独立冻结的工具链，doctor 通过）。实现者不要修改它；补丁应用与全量实验由 bench-runner 在主会话指示后执行。
- `tools/lost_capacity_report.py` 的 4.2 运行：B0 行为 `/Users/bytedance/Downloads/data/data/.claude/worktrees/admiring-merkle-4012a5/benchmark-results/20261005T160717720996Z_e2dc5610_6e2e98ae/rows.jsonl`，候选为同目录下 `20261005T184009696291Z_e2dc5610_eff2aaf0/rows.jsonl`；源码根目录用 `--source-root` 指向实现者自己的 worktree（解释改动后的代码为何接受或拒绝）；语料文件从各运行目录的 `inputs/` 或 `/Users/bytedance/Downloads/data/data/.claude/worktrees/phase-c-eval/` 读取，先查看 `rows.jsonl` 字段与 `inputs/` 结构确定单元到文件的映射。

## v2（主会话审查 v1 结果后）

v1 提交 `611f9a3a`（分支 `worktree-agent-ab0b746701fe1df05`）。预测失去容量单元 58 → 25，剩余 25 个均为真实安全拒绝或片段解析问题，接受。以下为必须修正的安全与语法问题，按优先级：

1. **C++ 引用别名**：被跨越节点中对标识符的写入（`assignment_expression` 的 left、`update_expression` 的操作数、复合赋值）若该标识符在整个翻译单元中曾以 `reference_declarator` 声明（含形参、范围 for 的 `auto &x`、结构化绑定），视同指针写入：后续声明有被跨越节点且 value 含标识符时拒绝。C 中无引用，此检查对 C 无影响。
2. **被跨越的 ERROR**：在 compound_statement 中，任一被跨越节点为 `ERROR` 或其子树含 `ERROR` 时，只允许"无被跨越节点"的合并。
3. **declare 语法回退清零**：审计中 c 5、cpp 4 个语法回退（如 `int i;` → `int, i;`）。当组内任一声明含 `ERROR` 子节点、`kind` 为空串或声明的名字列表中有空字符串时，跳过该组（`continue`），使语法回退在 c/cpp 都为 0。
4. **缩进幂等**：合并时首个声明的缩进取自组内最后一个声明，导致首个声明位于行中时（如 `CN373`）每次多一个空格。改为：首个声明若不在行首（其前同行有非空白字符），则不插入缩进、从 `first.start_byte` 开始替换；否则保持现有行为。要求：在全部语料上，除这些文件的空白差异外，declare 的输出与 v1 逐字节相同（用 v1 与 v2 对全量语料比较输出确认，回复中给出不同文件数及是否都只有空白差异）。
5. **array_init 干扰**：c 中 declare 与 array_init 干扰 25 → 29。查明新增 4 例原因；若能以"不跨越含数组初始化列表的声明"之类的简单守卫消除新增部分，则加；否则只报告原因。
6. 更新 `docs/RULES.md` 中 declare 与 while_to_for 的说明（守卫条件、while_to_for 回退形式），保持该文件现有体例。

验收：测试全部通过；declare 在 c/cpp 的语法回退为 0；幂等失败不高于 v1；重新运行 `tools/lost_capacity_report.py` 与离线容量预测，给出失去容量单元数（预期仍约 25，可能因 1–3 项略增，逐一列出新增单元及原因）。在同一分支追加一次提交。
