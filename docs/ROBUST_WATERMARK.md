# 鲁棒带密钥水印（阶段 2，实验性）

`cllmark/robust/` 是在旧版规则之上的第二种嵌入/检测方法：用**全部**可改写位点承载由密钥决定的比特，按位置无关的锚点寻址，检测只需密钥。它与旧版 BCH(7,4) 方法并存（旧版代码路径不变），是方法改动，结果与旧版论文不可直接比较。设计与修订过程见 [plans/2026-10-07-robust-watermark.md](plans/2026-10-07-robust-watermark.md)（v1–v4 与全量前修正），实验结果见 [2026-10-08-robust-watermark.md](experiments/2026-10-08-robust-watermark.md)（标签 `rw-eval-1`）：两个方案在手写代码上的误报都 ≤ α（BCH 基线 6–7%），方案 2 在 CodeNet 上 α = 1e-6 时检出 99.2–99.8%，`struct` 锚点抵抗改名。

## 为什么

旧版方法每个单元只用 7 个位点、按位置读取、依赖嵌入时保存的支持文件，而且误报率取决于选了哪个消息：未加水印的手写 JavaScript 有 84–96% 解码为 `0000`（[CodeNet v2 记录](experiments/2026-10-07-codenet-v2.md)）。CodeNet 生成代码在节点粒度有 90–200 个可用位点，绝大部分没有用上。

## 方法

**密钥与 PRF。** 32 字节密钥 K；PRF(K, x) = HMAC-SHA256(K, 域标签 ‖ x)，域标签 `white`/`role`/`seq`/`tag` 互相隔离（`cllmark/robust/keys.py`）。

**位点与锚点。** 位点沿用 `cllmark/nodes.py` 的节点粒度位点（每个规则对在每个可改写节点上一个位点，读数 0/1）。每个位点的“锚点键”是上下文的哈希，与位置、文件名无关：

- `tok`：规则对 + 所在函数名 + 节点内标识符与字面量（去掉规则自身会增删的名字）。抵抗重排、格式化、删除/插入代码；改名会改变它。
- `struct`：规则对 + 节点结构骨架（标识符抽象为 `ID`，可交换运算排序，规则对的两种形式摘要相同）。抵抗改名；不同位置更容易撞键。

键相同的位点合成一票（读数取多数，平票不投）。每票的目标比特先异或 PRF(K, white, key) 白化，因此未加水印的代码对任何消息的一致数都服从 Bin(n, 1/2)，与代码天然偏向哪种写法无关。

**选位。** 嵌入与检测在同一份代码上做同一个确定性选位：只取**白名单规则对**的 usable 位点，窗口互不重叠且不相邻，先序贪心。白名单 `cllmark/robust/stable_pairs.py` 由 `tools/robust_calibrate.py` 在默认语料（不含 CodeNet）上标定：某规则对的位点在单独改写后锚点键不变的比例 ≥ 0.95、且至少 10 个位点才入选（`declare`、`for_OOO`、`while_to_for`、`else_after_return` 等两种形式落在不同节点上的规则对被排除）。嵌入只对选中的位点做自稳定性检查，不稳定的不设置；检测不做稳定性检查（大仓库也只需不到 1 秒）。

**两个方案**（消息 4 或 8 位，`Scheme(name, bits, anchor)`）：

- `s1`：按 PRF(K, role, key) 把一半的票分给消息位（重复嵌入 m 的各位），另一半放 HMAC 标签 PRF(K, tag, m ‖ key)。纠错位不嵌入。已知 m 的判定只用标签票；盲提取先对每位多数表决，再用标签检验候选（Bonferroni 校正）。
- `s2`：所有票放 PRF(K, seq, m ‖ key)。已知 m：二项检验；盲提取：对 2^k 个消息取最小 p 值并乘以 2^k。

两个方案的错误消息 m′ 与 m 的目标相互独立，所以“只差一位的消息被误接受”的概率与随机代码相同（≈ α）。

## 用法

```python
from cllmark.robust import Scheme, derive_key, embed, detect
from cllmark.transform import StyleTransformer

transformer = StyleTransformer("python")  # 规则集与旧版相同（legacy 或 extended）
scheme = Scheme("s2", 4, "struct")
key = derive_key("secret seed")  # 部署时使用保密的 32 字节密钥
result = embed(transformer, "python", files, scheme, key, [1, 0, 1, 1])  # files: {文件名: 源码}
marked = {**files, **result.written}
found = detect(transformer, "python", marked, scheme, key, [1, 0, 1, 1])  # found.p_known
blind = detect(transformer, "python", marked, scheme, key, None)  # blind.decoded, blind.p_blind
```

`EmbedResult` 给出票数、设上率、选位一致性（标记后代码重新选位与嵌入时选位的 Jaccard）、不稳定的选中位点数与规则异常数；`Detection` 给出票数、一致数、`p_known`、盲提取结果 `decoded`/`p_blind`/`margin`、逐文件票数，以及只作参考的 `p_all`。判定：p ≤ α（实验用 1e-3 与 1e-6）。

## 评估

10 份配置 `benchmarks/config-rw-{s1,s2}-{4,8}-{tok,struct}.json` 与基线 `config-rw-bch-{file,node}.json`（`robust` 节选择 `benchmarks/robust_engine.py`）。组：CodeNet 四种语言的生成组（嵌入）与手写组（只检测，零假设）、`python/c/cpp_projects`（多文件项目，嵌入）、`js_repos`（14 个手写仓库，只检测）、`js_repos_stress`（同样的仓库嵌入后运行仓库自带测试，只计功能保持）。每个单元的消息由 seed 与单元 ID 派生；攻击（`benchmarks/attacks.py`）：`flip_0.1/0.2/0.3`、`normalize_1/3/all`、`delete_0.25/0.5`、`insert_1`、`rename`、`reformat`、`reorder`、`combo`，同时施加于标记代码与手写代码。`normalize_all` 把全部风格证据抹到随机水平，任何基于公开规则集的风格水印都不能抵抗，如实报告、不作通过条件。

```bash
.venv-benchmark/bin/python tools/research_loop.py run --config benchmarks/config-rw-s2-4-tok.json --jobs 60
.venv-benchmark/bin/python tools/robust_report.py RUN_DIR [RUN_DIR ...] --output report.md   # 变体对比报告
.venv-benchmark/bin/python tools/robust_calibrate.py [--output X.json]                        # 重新标定白名单
.venv-benchmark/bin/python tools/robust_sample.py run OUT.tsv [--pairs X.json]                # 核心抽样（每语言 20+20 个 CodeNet 文件）
.venv-benchmark/bin/python tools/robust_sample.py compare v2=A.tsv v4=B.tsv
```

报告（`tools/robust_report.py`）分 8 节：总表、容量、嵌入与功能保持、无攻击检测、零假设（全部消息上的经验误报率与 p 值分布）、跨消息误接受、攻击、按规则对的稳定性。功能回退按 [docs/experiments/2026-10-08-robust.bisect.py](experiments/2026-10-08-robust.bisect.py) 逐样式归因。全量应在 Linux x86_64 + GCC 上运行（CodeNet oracle 见 [CODENET.md](CODENET.md)）。

## 已知限制

- 规则集是公开的：攻击者统一改写所有规则对（`normalize_all`）即可抹去水印，这一点与旧版方法相同。
- `tok` 锚点不抵抗改名，`struct` 锚点抵抗改名但票数约为 `tok` 的一半；项目级的 C++ 生成代码位点少（中位数约 16 票），在严格 α 下检出率明显低于 CodeNet。
- 嵌入改写全部选中位点，比 BCH 的 7 个槽位更容易触到规则的边界情形；2026-10-08 的规则修复见 [plans/2026-10-08-rule-fixes-robust.md](plans/2026-10-08-rule-fixes-robust.md) 与 [RULES.md](RULES.md)。
- 预期消息检验与盲提取都只用密钥，不需要支持文件；但它们仍是风格水印，语义等价性由规则守卫与功能测试保证，不能由语法正确推出。
