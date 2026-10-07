# CodeNet 生成/手写数据集的全方位评估（v1）

## 目标与范围

用户要求在数据集 [Noelle1831-k/dataset](https://github.com/Noelle1831-k/dataset)（固定提交 `8f5f30e8309618f671b29eaa9af7681c7fc06662`）上全方位测试当前方法：`generated/<pid>/sol.{py,c,cpp,js}` 是大模型生成代码（role generated），`solutions/<pid>/ref.{py,c,cpp,js}` 是手写标准答案（role human）。题目是 CodeNet 的 stdin/stdout 程序题，`hf/{python,c,cpp,js}.jsonl` 每题带 `test_cases`（`input`/`expected`/`set`，平均 11 条，四种语言的用例逐题完全相同，已核实）。

“全方位”= 对 8 个组（4 语言 × G/H）在 4 种方法变体（文件粒度/节点粒度 × legacy/extended 规则集）上，测量框架已有的全部指标：容量与可嵌入率、预期消息恢复、检测 TPR/FPR、BCH 纠错、规则性质（幂等/可逆/独立）、反向规则攻击 flip_1/flip_2、语法有效性、功能保持（新 stdin/stdout oracle）、耗时；另加一个跨变体汇总报告（G 与 H 对比、回退样本按规则归因、逐用例通过率变化）。

**属于工程改动**（新语料导入、新 oracle、新配置、报告工具）。**不改变方法协议**：不改 `cllmark/`，不改规则、嵌入/提取算法；不改默认配置及其度量协议文件。

## 关键约束（证据）

- `benchmarks/common.py:150` `protocol_fingerprint` 对 `common.py`、`engine.py`、`utility.py`、`metrics.py`、`include/bits/stdc++.h` 取摘要，`benchmarks/compare.py:18` 指纹不同即不可比。**这五个文件必须逐字节不变**，否则默认基线失效。新 oracle 放到新文件 `benchmarks/codenet.py`，仿照 `node_engine.protocol_config` 的做法：只有带 `"codenet"` 键的配置把该文件摘要加入协议配置。
- `common.validate_config`（`benchmarks/common.py:96`）只接受已有 oracle 名。不改它；在 `tools/research_loop.py:read_config` 中先调用 `codenet.validate_config`，再把 codenet 组的 oracle 临时映射为 `"none"` 的副本交给 `common.validate_config` 校验，返回的仍是原配置（见下）。
- 功能测试走 `benchmarks/staged.py:functional_unit`（`runner.py:242` 默认使用 staged worker），它直接调用 `utility.evaluate_utility`。把这一调用改为 `codenet.evaluate_utility`（分派器：codenet oracle 自己处理，其他 oracle 原样委托给 `utility.evaluate_utility`，参数与返回值不变）。`staged.py` 不在度量摘要中。
- `discover_units`（`common.py:349`）的 function 级单元是 cohort 目录下 `*<ext>` 的平铺文件，单元名 = 文件名 stem；输入必须在仓库根之内且不能是符号链接（`runner.py:78`）。因此语料要**复制**到仓库内被忽略的目录。不得写入 `corpus/`。
- 题目集合：`hf/python.jsonl` 的 1000 个 pid。`generated/` 也有 1000 个目录，但多出 `p00000`（不在 hf 中）、缺 `p03802`。G 组取交集（999 题），JS_H 只有 511 题（`solutions/<pid>/ref.js` 存在者，与 `hf/js.jsonl` 一致）。排除项写入导入报告，不静默丢弃。
- 判题规则来自数据集 `testdata/<pid>/meta.json` 的 `checker.type`：955 题 `token+float:1e-6`，45 题 `token`（数据集 `lib/checker.py` 语义：先逐 token 比较，不等再按 1e-6 相对/绝对容差比较数值 token）。时限 `time_limit_ms` 取自 hf 行（1000/2000/3000/8000 ms）。数据集的编译参数（`lib/runner.py:16-17`）：C `gcc -O2 -std=c11 -pipe ... -lm`，C++ `g++ -O2 -std=c++17 -pipe`。

## 逐文件改动

### 1. `benchmarks/codenet.lock.json`（新）

```json
{"repository": "https://github.com/Noelle1831-k/dataset.git",
 "commit": "8f5f30e8309618f671b29eaa9af7681c7fc06662",
 "output": "external/codenet"}
```

### 2. `tools/import_codenet.py`（新）

`python tools/import_codenet.py [--source PATH]`。
- 无 `--source` 时 `git clone --filter=blob:none --no-checkout` 到 `.benchmark-cache/codenet-src`，`git checkout <commit>`（已存在则只校验）。有 `--source` 时校验其 `git rev-parse HEAD` 等于锁定提交，否则报错退出。
- 输出到锁文件的 `output`（`external/codenet/`，加入 `.gitignore`）：
  - `dataset/{Python,C,CPP,JS}_{G,H}/<pid>.<ext>`：G 来自 `generated/<pid>/sol.<ext>`，H 来自 `solutions/<pid>/ref.<ext>`；只收 hf 题目集合内的 pid。字节原样复制。
  - `problems.jsonl`：每题一行 `{"task_id": "<pid>", "title", "source", "time_limit_ms", "memory_limit_mb", "checker": "<meta checker.type>", "test_cases": [...]}`，test_cases 取 `hf/python.jsonl`；断言其他三份 hf 文件中同 pid 的 test_cases 完全一致，不一致即报错。
  - `import-report.json`：锁定提交、各组文件数、排除项及原因（`p00000`: generated 有但无 hf 测试；`p03802`: hf 有但无生成代码；JS_H 缺失的 489 题）、所有输出文件的 SHA-256 汇总摘要。
- 幂等：输出已存在且摘要一致时不改动；不一致时清空 `external/codenet/` 重建。
- Makefile 增加 `codenet-setup:` 目标调用它（用 `.venv-benchmark/bin/python`）。

### 3. `benchmarks/codenet.py`（新）

- `ORACLE = "codenet_stdio"`。
- `protocol_config(config, root)`：配置无 `"codenet"` 键原样返回；否则返回 `{**config, "codenet_oracle_sha256": digest(本文件字节)}`。在 `benchmarks/rule_sets.py:protocol_config` 末尾链式调用（先现有逻辑，再 `codenet.protocol_config`）。
- `validate_config(config)`：若存在 `oracle == "codenet_stdio"` 的组，要求：`level == "function"`、语言属于 python/c/cpp/javascript、`config["codenet"]` 含 `time_factor`（>0 数字）与 `problem_file`（`problem_files` 中的键）。然后对一份深拷贝（codenet 组 oracle 改为 `"none"`）调用 `common.validate_config`，**返回原 config**。`tools/research_loop.py:read_config` 改为调用它（对没有 codenet 组的配置行为与之前完全一致）。
- 判题器：移植数据集 `lib/checker.py` 的 `check_token`、`check_float`、`check_token_float` 语义；`checker` 字符串 `token` → 逐 token；`token+float:<eps>` → token 不等再按 eps 数值比较。其他值报 `ValueError`。
- `evaluate_utility(unit, directory, problems, config, run_dir, environment, cache_root)`：`unit["oracle"] != ORACLE` 时 `return utility.evaluate_utility(...)` 原样委托。否则：
  - `task_id = Path(unit["source_files"][0]).stem`；`problem = problems[config["codenet"]["problem_file"]].get(task_id)`，缺失返回 `{"status": "NO_TEST_ORACLE", "task_id": task_id}`。
  - 构建：python 用 `compile(code, ...)` 检查（SyntaxError → COMPILE_ERROR），运行 `[environment["python_executable"], prog.py]`；javascript `node --check` 后 `[node, prog.js]`；c 用 `shutil.which("cc")`，`-std=c11 -O2 -pipe src -o exe -lm`；cpp 用 `environment["compiler"]`，`-std=c++17 -O2 -pipe src -o exe`。编译超时 `compile_timeout_seconds`。编译器版本（`cc --version` 首行）进入缓存身份。
  - 逐用例运行：stdin 为该用例输入文件，stdout/stderr 写入缓存目录 `case-<i>.stdout/.stderr`（复用 `utility.subprocess_limits` 的 RLIMIT；需要一个带 stdin 文件的 `run_process` 变体，写在本文件内，不改 `utility.py`），超时 = `time_limit_ms / 1000 * config["codenet"]["time_factor"]`；超时按 `test_timeout_retries` 重试，与 `utility.run_test` 语义一致（记录每次尝试、`recovered_after_timeout`）。环境 `PYTHONHASHSEED=seed`。
  - 用例判定：`TLE`（最终超时）、`RE`（返回码非 0）、`WA`（checker 不通过）、`AC`。出现第一个最终 TLE 后其余用例记 `SKIPPED` 不再运行。
  - 单元状态：编译失败 `COMPILE_ERROR`/`COMPILE_TIMEOUT`；有 WA 或 RE → `FAIL`；否则有 TLE → `TIMEOUT`；全 AC → `PASS`（这些都在 `metrics.TESTED` 中）。
  - 结果字段：`task_id`、`test_kind: "codenet_stdio_cases"`、`cases_total`、`cases_passed`、`verdict_counts`、`cases`（每条：name/set/verdict/elapsed_ms/attempts/detail≤200 字符）、`first_failure`、`oracle_sha256 = digest(problem)`、`cache_key`、`cache_hit`、`artifacts`。
  - 缓存：身份 = 语言、源码摘要、`digest(problem)`、编译器路径与版本、编译参数、`time_factor`、retries、node 版本、python 可执行路径与版本、本文件摘要。目录放在 `cache_root / "codenet" / key`，加 `utility.cache_lock`；TIMEOUT 与 COMPILE_TIMEOUT 不缓存（与 `utility.py` 一致）。
  - 产物：照 `utility.evaluate_utility` 的方式把程序、compile 日志、`case-*.stdout/stderr`（最多前 20 个文件）与 `result.json` 复制到 `directory/.utility`。

### 4. `benchmarks/staged.py`

只把 `functional_unit` 中的 `evaluate_utility` 改为 `codenet.evaluate_utility`（导入改为 `from . import codenet`）。非 codenet 单元调用路径与结果不变。

### 5. 四份配置（新）

`benchmarks/config-codenet.json`、`config-codenet-extended.json`、`config-codenet-node.json`、`config-codenet-node-extended.json`。从对应的 `config.json`/`config-extended.json`/`config-node.json`/`config-node-extended.json` 复制非 cohort 字段（seed、watermark、attacks、rule_properties、gates、test_timeout_retries、各自的 `rule_set`/`slot_granularity`），然后：
- `"problem_files": {"codenet": "external/codenet/problems.jsonl"}`，`"projects": {}`，去掉 `exercism`（若 validate 需要则保留原值）。
- `"codenet": {"problem_file": "codenet", "time_factor": 3}`。
- `"unit_timeout_seconds": 900`。
- 8 个组：`codenet_{python,c,cpp,javascript}_{generated,human}`，`path: external/codenet/dataset/<Dir>_<G|H>`，`level: function`，`oracle: codenet_stdio`，role 分别为 generated/human。

### 6. `tools/codenet_report.py`（新）

`python tools/codenet_report.py RUN_DIR [RUN_DIR ...] --output PATH.md`。读取每个运行的 `manifest.json`（变体名由 `slot_granularity`/`rule_set` 得出）与 `rows.jsonl`，输出 Markdown（并同名 `.json`）：
1. 每个变体 × 组一行：单元数、可嵌入率、容量中位数/均值、标记后恢复率、原始（未嵌入）代码误匹配率（G 与 H 分别算；H 即 FPR）、`correct_bits` 均值、flip_1/flip_2 完整施加率与施加后恢复率、嵌入后语法有效率、性质探测通过率（幂等/可逆/独立）、功能 before 通过率、配对保持率、回退数、harness_error 数、分析/嵌入耗时中位数。
2. G vs H 对比（每种语言、每个变体）：容量、可嵌入率、恢复率差值。
3. 功能回退清单：每个回退单元的 id、before/after 状态、首个失败用例、`embedding_slots` 中的规则；并按规则汇总回退次数（某规则出现在回退单元的次数 / 出现在所有配对单元的次数）。
4. 逐用例通过率：before 与 after 的 `cases_passed/cases_total` 合计，及 after 中“部分用例回退”的单元数。
5. H 组 before 未通过的单元清单（标准答案应全部通过；未通过说明判题环境差异，需逐条列出状态与首个失败用例）。
字段缺失（节点粒度行字段名不同）时用 `.get` 跳过并在表中写 N/A，不得报错。

### 7. 测试 `tests/test_codenet.py`（新）

- 判题器：token 相等/不等、浮点 1e-6 容差内外、token 数不同、非数值 token。
- oracle（用临时目录与内存构造的 problem，每种语言至少一例 PASS）：C 的 PASS、WA、RE（非零退出）、COMPILE_ERROR；Python 的 TLE（`time_limit_ms` 很小 + `time_factor` 1 + `while True: pass`，retries=0）→ `TIMEOUT`，且后续用例为 `SKIPPED`；JavaScript 读 `/dev/stdin` 的 PASS。第二次调用命中缓存（`cache_hit` 为真）。
- 分派：oracle 为 `none` 的单元经 `codenet.evaluate_utility` 返回与 `utility.evaluate_utility` 相同的 `NO_TEST_ORACLE` 结果。
- 配置：`codenet.validate_config` 接受 `benchmarks/config-codenet.json`（不要求语料存在）；`rule_sets.protocol_config(默认 config.json)` 不含 `codenet_oracle_sha256`，且与改动前结果相同（直接断言键不存在即可）；codenet 配置含该键。
- 导入器：在临时目录构造一个两题的假数据集 git 仓库（含 hf 四文件、testdata meta、generated、solutions），用 `--source` 跑通，检查目录结构、`problems.jsonl` 与排除项；提交不匹配时报错。为此允许导入器接受隐藏参数 `--commit`（仅测试用）覆盖锁定提交。

### 8. 文档

`docs/CODENET.md`（新）：来源与固定提交、G/H 定义、排除项、oracle 定义（编译参数、时限 × time_factor、判题器、单元状态规则、无内存限制）、四份配置、运行命令与报告工具。`docs/RESEARCH_LOOP.md` 末尾加一小节链接它。README 目录结构不必改。

## 验收标准

1. `make lint`、`make test` 全部通过（含新测试）。
2. `git diff --stat` 中 `benchmarks/common.py`、`engine.py`、`utility.py`、`metrics.py`、`include/` 与 `cllmark/` 无改动。
3. `make codenet-setup` 成功：组文件数 Python/C/CPP/JS 的 G 均为 999，H 为 1000/1000/1000/511；`problems.jsonl` 1000 行。
4. （由 bench-runner 完成）`make smoke` 通过；`research_loop.py run --config benchmarks/config-codenet.json --limit 2` 正常完成、无 harness_error。

## 禁止事项

- 不改 `cllmark/`、规则、BCH；不改度量协议五个文件；不写 `corpus/`；不改或提升 `benchmarks/baselines/`。
- 不删除或跳过任何失败样本；导入时只排除上面列明的缺失项。
- 不运行全量 benchmark（由 bench-runner 负责）。

## v2：手写组只测天然误报（不嵌入）

用户纠正实验设计：手写代码不嵌入水印再提取，而是检验未加水印的手写代码是否天然读出水印而误报。生成代码照旧嵌入（恢复、攻击、功能保持）。**属于评估协议改动，只作用于带 `"codenet"` 键的配置**（`codenet.py` 的摘要已在其协议配置中），默认配置的协议指纹不变。

### 1. 配置

四份 `config-codenet*.json` 的四个 human 组加 `"embed": false`。`codenet.validate_config`：`embed` 只能是布尔值，只允许出现在 codenet_stdio 组上。

### 2. `benchmarks/codenet.py`：只检测的单元

- 新函数 `install(engine_instance)`：若 `engine_instance.config` 含 `"codenet"`，把实例的 `evaluate` 包装为：`unit.get("embed", True)` 为真时调用原 `evaluate`；为假时调用 `detect_only(engine_instance, unit)`。在 `benchmarks/staged.py:initialize_worker` 末尾（stub 替换之后）调用 `codenet.install(engine.ENGINE)`。
- `detect_only(engine, unit)` 产出与原行相同的字段集合，步骤：按原 `evaluate` 的方式把冻结输入复制到 `work/clean`（校验 SHA-256）；分析用 `engine.nodes.analyze_directory`（节点粒度，`hasattr(engine, "nodes")`）或 `engine.directories.analyze_directory`；记录 `capacity`、`required_capacity`、`eligible`、`syntax_before`、`analysis_ms`；**对所有单元（含容量不足者）**调用 `engine.extract(clean, language, unit["id"], "original")` 得到 `original_extraction`，异常时记为 `{"error": repr(e), "matched": False, "raw_matched": False, "bits": []}`；`embedded: False`；`properties: None`、`embedding_slots: []`、`marked_extraction: None`、`attacks: {}`、`syntax_after: {}`；`utility_before = engine_module.evaluate_utility(...)`（staged 下为 DEFERRED 占位），`utility_after = {"status": "NOT_EMBEDDED"}`；写 `legacy.log` 与 `result.json`、`elapsed_ms`、`artifacts`，与原 evaluate 一致。实现前先确认容量 < 7 时两种粒度的提取行为（是否调用 `bch.decode`、读出几位），写进 docstring。
- `benchmarks/staged.py:functional_unit`：`after` 在 `not row["eligible"] or row.get("embedded") is False` 时为 `NOT_EMBEDDED`。

### 3. 报告 `tools/codenet_report.py`

- 生成组（role generated）照旧：可嵌入率、容量、恢复、攻击、语法、功能保持、回退清单与规则归因、逐用例统计；另加“未嵌入时天然匹配率”（original_extraction）。
- 手写组只出检测表：单元数、容量分布（中位数、均值、<7 的数量）、读出完整 7 位的单元数；对水印 `1010`：天然匹配率（分母分别为全部单元、读出 7 位的单元）、码字逐位精确匹配率（raw）；**16 种消息的误报率**：用 `cllmark.bch.decode` 解码每个单元的 bits，误报率(m) = 解码结果等于 m 的单元比例（同上两种分母），列出最大值、对应消息、均值，以及解码结果分布的前 5 名；同样对生成组的未嵌入原始代码给出这张表（对照）。
- 删除手写组的恢复/攻击/功能保持/回退列；第 5 节（手写参考在嵌入前未通过）保留，作为判题环境自检。
- 新增“检测对照”表：每个变体 × 语言，TPR（生成组嵌入后恢复）与 FPR（手写组全部单元天然匹配 `1010`）及 16 消息最大 FPR。

### 4. 测试

`tests/test_codenet.py` 增加：`detect_only` 在一个最小 python 单元上不产生 `marked` 目录、`embedded` 为假、`original_extraction` 存在；`install` 对 `embed` 为真的单元调用原 evaluate；validate 拒绝非布尔 `embed`；报告的 16 消息误报率在构造的 rows 上计算正确（分布之和为 1）。

### 验收

`make lint`、`make test` 通过；默认 `config.json` 的协议指纹不变（测试断言 `rule_sets.protocol_config(默认配置)` 不含 codenet 键）；`research_loop.py run --config benchmarks/config-codenet.json --limit 2` 正常，human 行无 marked 目录。
