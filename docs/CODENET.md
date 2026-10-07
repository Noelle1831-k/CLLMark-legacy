# CodeNet 生成/手写数据集评估

这是工程改动：新语料导入、新功能 oracle、新配置和报告工具。方法协议没有改变（`cllmark/`、规则、嵌入/提取算法、BCH 不变），默认配置与其基线不受影响。

评估协议只作用于带 `"codenet"` 键的配置：生成组（G）照常嵌入、提取、攻击并测功能保持；手写组（H）**不嵌入**，只检验未加水印的手写代码是否天然读出水印而误报（见“手写组只检测”）。

## 来源与固定提交

数据集 [Noelle1831-k/dataset](https://github.com/Noelle1831-k/dataset)，固定提交 `8f5f30e8309618f671b29eaa9af7681c7fc06662`（`benchmarks/codenet.lock.json`）。题目是 CodeNet 的 stdin/stdout 程序题，题目集合取 `hf/python.jsonl` 的 1000 个 pid；`hf/{python,c,cpp,js}.jsonl` 中同一 pid 的 `test_cases` 完全相同（导入时断言）。

- G 组（role generated）：`generated/<pid>/sol.{py,c,cpp,js}`，大模型生成。
- H 组（role human）：`solutions/<pid>/ref.{py,c,cpp,js}`，手写标准答案。

导入器字节原样复制到被忽略的 `external/codenet/dataset/{Python,C,CPP,JS}_{G,H}/<pid>.<ext>`（不写 `corpus/`）。

例外：数据集 1006 份 `ref.py` 中有 958 份是同一个适配器模板（`solve(data)` 把 base64 编码的 CodeNet 原始提交写入临时文件并用子进程运行）。对它嵌入水印测量的是共享模板而不是手写代码（文件粒度下 954 份容量相同、节点粒度下未嵌入代码的预期消息误匹配率达 97%），所以 Python_H 改用解码出的原始提交（独立的 stdin/stdout 程序）。解包的题目列在导入报告的 `unwrapped` 中；其余 42 份是普通程序，原样复制。其他语言的参考解没有这种包装。

## 排除项

导入报告 `external/codenet/import-report.json` 逐项列出：

- `p00000`：`generated/` 有代码但 hf 没有该题的测试。
- `p03802`：hf 有该题但没有生成代码（四种语言的 G 组各少一题，各 999 题）。
- JS_H 缺 489 题：没有手写 JavaScript 解答（也不在 `hf/js.jsonl`），JS_H 为 511 题。
- `generated/.queue` 不是题目目录，不计入。

组文件数：G 四种语言均 999，H 为 Python/C/CPP 1000、JS 511。

## 手写组只检测（`"embed": false`）

四份配置的四个 human 组带 `"embed": false`（`codenet.validate_config` 只接受布尔值，且只允许出现在 `codenet_stdio` 组上）。`benchmarks/staged.py:initialize_worker` 在 stub 替换之后调用 `codenet.install(engine.ENGINE)`：带 `codenet` 键的配置把引擎的 `evaluate` 包装成，`embed` 为真（缺省）时走原流程，为假时走 `codenet.detect_only`。

`detect_only` 的行与嵌入路径有相同的字段：分析（文件粒度用 `directories`，节点粒度用 `nodes`）后记录 `capacity`、`required_capacity`、`syntax_before`，对**所有**单元（含容量不足者）在未改动的 `clean` 副本上提取，得到 `original_extraction`；不创建 `marked`，`embedded` 为假，`marked_extraction` 为 `None`，`attacks`/`syntax_after` 为空，`properties` 为 `None`，`embedding_slots` 为空，`utility_after` 为 `{"status": "NOT_EMBEDDED"}`；`utility_before` 照常由功能阶段填入。两处与嵌入路径的行不同：

- `eligible` 记为假（不是水印候选）。`metrics.summarize_group` 对每个 eligible 行读取 `marked_extraction`，而 `metrics.py` 属于协议文件不能改，所以手写行必须不是 eligible；是否够 7 位另记在 `capacity_sufficient`。内置报告里 H 组的 FPR 因此没有分母（N/A），以 `tools/codenet_report.py` 的检测表为准。
- 不输出 `embedding_ms`、`changed_files`（与容量不足的嵌入行一致）。

容量 < 7 时的提取行为（两种粒度相同，已在小运行中核对）：仍调用 `bch.decode`，传入的是实际有的槽位的位（文件粒度每个可用规则对一个槽位，节点粒度取存储的前 7 个槽位），所以读出位数为 `min(容量, 7)`。`bch.decode` 把较短的词当整数右对齐读入（再做一次单比特纠错），所以短词解码为其数值所蕴含的消息，容量 0 时空词解码为 `0000`；原始码字（7 位）在不足 7 位时不可能精确匹配。读不出的槽位（两种样式都适用或都不适用）取按单元播种的随机位，规则抛异常的槽位不产出位。

## 导入与运行

```bash
make codenet-setup                  # 克隆到 .benchmark-cache/codenet-src 并检出锁定提交，再导入
make codenet-setup SOURCE=PATH      # 使用已有检出（必须在锁定提交上）
.venv-benchmark/bin/python tools/research_loop.py run --config benchmarks/config-codenet.json --limit 2
.venv-benchmark/bin/python tools/codenet_report.py RUN_DIR [RUN_DIR ...] --output docs/experiments/NAME.md
```

导入幂等：输出已存在且摘要一致时不改动，不一致时清空重建。`problems.jsonl` 每题一行：`task_id`、`title`、`source`、`time_limit_ms`、`memory_limit_mb`、`checker`（取自 `testdata/<pid>/meta.json` 的 `checker.type`）、`test_cases`。

## 四份配置

`benchmarks/config-codenet.json`（文件粒度/legacy）、`config-codenet-extended.json`（文件粒度/extended）、`config-codenet-node.json`（节点粒度/legacy）、`config-codenet-node-extended.json`（节点粒度/extended）。各自沿用对应 `config*.json` 的 seed、水印、攻击、性质探测、门禁和 `rule_set`/`slot_granularity`，有 8 个组 `codenet_{python,c,cpp,javascript}_{generated,human}`，`oracle` 为 `codenet_stdio`，`"codenet": {"problem_file": "codenet", "time_factor": 3}`，`unit_timeout_seconds` 为 900。带 `codenet` 键的配置把 `benchmarks/codenet.py` 的摘要加入协议配置；五个度量协议文件不变。

## 功能 oracle（`benchmarks/codenet.py`）

- 构建：Python 用 `compile` 检查语法，JavaScript 用 `node --check`；C 用 `cc -std=c11 -O2 -pipe src -o exe -lm`；C++ 用 `c++ -std=c++17 -O2 -pipe src -o exe`；只有编译器自身没有 `<bits/stdc++.h>`（macOS libc++）时才加 `-I benchmarks/include` 兼容头，GNU libstdc++ 使用自带的头。数据集参考解在 Linux gcc/g++ 上验证，全量应在 Linux x86_64 + GCC 上运行（macOS 下的 `std::stdin`、x86 intrinsics、`malloc.h` 等失败属于平台差异）。
- 逐用例运行：stdin 为用例输入；时限为 `time_limit_ms / 1000 * time_factor`，超时按 `test_timeout_retries` 重试；没有内存限制。
- 判题器（移植数据集 `lib/checker.py`）：`token` 逐 token 比较；`token+float:<eps>` 先逐 token，不等再按 `eps * max(1, |期望|)` 做数值比较。
- 用例判定 `AC/WA/RE/TLE`；出现第一个最终 TLE 后其余用例记 `SKIPPED`。
- 单元状态：编译失败 `COMPILE_ERROR`/`COMPILE_TIMEOUT`；有 WA 或 RE 为 `FAIL`；否则有 TLE 为 `TIMEOUT`；全 AC 为 `PASS`。TIMEOUT 与 COMPILE_TIMEOUT 不缓存。
- 其他 oracle 原样委托给 `utility.evaluate_utility`。

## 已知环境限制

编译用本机工具链。数据集参考解在 Linux gcc 上验证；全量在 Linux x86_64 + GCC 13 服务器上运行，H 组 before 通过率 99.9%（未通过的 2 份见报告第 5 节）。macOS 上的 clang/libc++ 与 gcc 不完全兼容，会产生额外的编译失败，这些按 `COMPILE_ERROR` 如实计入而不是排除。

## 报告工具

`tools/codenet_report.py` 输出（Markdown 加同名 JSON，节点粒度行缺少的字段显示 N/A）：

1. 生成组：变体 x 组汇总（可嵌入率、容量、恢复、攻击、语法、性质、功能保持、耗时；“natural match”是未嵌入时天然匹配率）。
2. G 与 H 容量对比（H 不嵌入，没有恢复/保持可比）。
3. 功能回退清单及按规则归因（只含生成组）。
4. 逐用例通过率变化（只含生成组）。
5. H 组 before 未通过清单（判题环境自检，保留）。
6. 未嵌入代码的检测表（手写组，另给生成组未嵌入原始代码作对照）：单元数、容量中位数/均值/`<7` 个数、读出完整 7 位的单元数；对水印 `1010` 的天然匹配率（分母为全部读出的单元与读出 7 位的单元）、码字逐位精确匹配率；16 种消息的误报率（用 `cllmark.bch.decode` 解码每个单元的位，误报率(m) = 解码结果为 m 的单元比例，两种分母），列出最大值与对应消息、均值和解码结果前 5 名。提取抛异常的单元计入分母但不属于任何消息（分布中以 `error` 列出）。
7. 检测对照：每个变体 x 语言的 TPR（生成组嵌入后恢复）、FPR（手写组天然匹配 `1010`，两种分母）、手写组 16 消息最大误报率。
