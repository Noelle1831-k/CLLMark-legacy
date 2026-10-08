# 鲁棒带密钥水印（阶段 2，实验性）

`cllmark/robust/` 是在旧版规则之上的第二种嵌入/检测方法：用**全部**可改写位点承载由密钥决定的比特，按位置无关的锚点寻址，检测只需密钥。它与旧版 BCH(7,4) 方法并存（旧版代码路径不变），是方法改动，结果与旧版论文不可直接比较。设计与修订过程见 [plans/2026-10-07-robust-watermark.md](plans/2026-10-07-robust-watermark.md)（v1–v4 与全量前修正），实验结果见 [2026-10-08-robust-watermark.md](experiments/2026-10-08-robust-watermark.md)（标签 `rw-eval-1`）：两个方案在手写代码上的误报都 ≤ α（BCH 基线 6–7%），方案 2 在 CodeNet 上 α = 1e-6 时检出 99.2–99.8%，`struct` 锚点抵抗改名。

## 主选方法（2026-10-09 决定）

**方案 2 + `struct` 锚点，4 位消息**（配置 `config-rw-s2-4-struct.json`）是本方法；其余变体只作消融：`tok` 锚点（票数多、但改名即失效）、方案 1（消息位 + 标签，判定只用一半的票）、8 位消息（容量扩展）。选择依据是叙述最简单、每个部件都是常见做法：

- 每个可改写位点承载一个由密钥决定的伪随机比特（序列水印），没有纠错码、标签、角色分配等额外结构；
- 位点用抽象语法树骨架的哈希寻址（标识符抽象掉），对改名、重排、格式化、删改代码不变，这是代码克隆检测里常用的思路；
- 检测是标准的二项检验，误报率由 α 直接控制、与消息无关；不知道消息时对全部消息取最小 p 值并做 Bonferroni 校正；
- 4 位与旧版方法的载荷相同，便于和 BCH 基线逐项对比；8 位作为“同一机制可扩展到 256 个来源”的补充结果。

## 叙述主线

1. **问题**：旧版方法每个单元只用 7 个位点、按位置读取并依赖嵌入时保存的支持文件；误报率取决于所选消息（手写 JavaScript 84–96% 读出 `0000`，BCH 基线在 CodeNet 手写代码上误报 6–7%）。
2. **方法**：用全部可改写位点 × 结构锚点 × 密钥伪随机序列 × 二项检验。只使用“改写不会改变自身锚点”的规则对（在默认语料上一次性统计得到，不用评估数据）。
3. **主张与证据**（`rw-eval-1`，CodeNet 3,996 个生成单元 / 3,511 个手写单元）：
   - 误报可控：手写代码在 α = 1e-3 与 1e-6 下误报为 0；全部消息上的逐对误报率 ≤ α；错误消息（含只差一位的）被接受的概率 ≈ α。
   - 检出：α = 1e-6 时 99.2%（盲提取 97.7%），AUC 1.0；票数中位数 45（旧版 7 个槽位）。
   - 鲁棒：改名 98.8%、删除一半函数 99.2%、重排/格式化 100%、随机改写 3 个规则对 94.4%、翻转 10% 位点 99.0%（α = 1e-3）；BCH 文件粒度对应为 85.6%、94.4%、99.9%、86.6%、32.5%。
   - 功能保持：CodeNet 生成代码 0 个功能回退；14 个 JavaScript 仓库嵌入后 13 个自带测试全过（ejs 的测试比较函数源码文本）；规则层另经真实大仓库检查（旧版嵌入与逐规则全仓改写）57/57 通过。
4. **消融**：`tok` 锚点票数约为两倍、翻转与插入下更强，但改名后 9%；方案 1 在 α = 1e-6 时 68%；8 位与 4 位检出率相同，盲提取略低。
5. **局限**：攻击者统一改写全部规则对（`normalize_all`）可抹去任何基于公开规则集的风格水印；位点少的项目（C++ 项目中位数 14 票）在严格 α 下检出率低；源码反射（`Function.prototype.toString`）会看到改写。

## 为什么

旧版方法每个单元只用 7 个位点、按位置读取、依赖嵌入时保存的支持文件，而且误报率取决于选了哪个消息：未加水印的手写 JavaScript 有 84–96% 解码为 `0000`（[CodeNet v2 记录](experiments/2026-10-07-codenet-v2.md)）。CodeNet 生成代码在节点粒度有 90–200 个可用位点，绝大部分没有用上。

## 方法

**密钥与 PRF。** 32 字节密钥 K；PRF(K, x) = HMAC-SHA256(K, 域标签 ‖ x)，域标签 `white`/`role`/`seq`/`tag` 互相隔离（`cllmark/robust/keys.py`）。

**位点与锚点。** 位点沿用 `cllmark/nodes.py` 的节点粒度位点（每个规则对在每个可改写节点上一个位点，读数 0/1）。每个位点的“锚点键”是上下文的哈希，与位置、文件名无关：

- `tok`（消融）：规则对 + 所在函数名 + 节点内标识符与字面量（去掉规则自身会增删的名字）。抵抗重排、格式化、删除/插入代码；改名会改变它。
- `struct`（主选）：规则对 + 节点结构骨架（标识符抽象为 `ID`，可交换运算排序，规则对的两种形式摘要相同）。抵抗改名；不同位置更容易撞键。

键相同的位点合成一票（读数取多数，平票不投）。每票的目标比特先异或 PRF(K, white, key) 白化，因此未加水印的代码对任何消息的一致数都服从 Bin(n, 1/2)，与代码天然偏向哪种写法无关。

**选位。** 嵌入与检测在同一份代码上做同一个确定性选位：只取**白名单规则对**的 usable 位点，窗口互不重叠且不相邻，先序贪心。白名单 `cllmark/robust/stable_pairs.py` 由 `tools/robust_calibrate.py` 在默认语料（不含 CodeNet）上标定：某规则对的位点在单独改写后锚点键不变的比例 ≥ 0.95、且至少 10 个位点才入选（`declare`、`for_OOO`、`while_to_for`、`else_after_return` 等两种形式落在不同节点上的规则对被排除）。嵌入只对选中的位点做自稳定性检查，不稳定的不设置；检测不做稳定性检查（大仓库也只需不到 1 秒）。

**两个方案**（消息 4 或 8 位，`Scheme(name, bits, anchor)`；主选 `s2`，`s1` 为消融）：

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
.venv-benchmark/bin/python tools/research_loop.py run --config benchmarks/config-rw-s2-4-struct.json --jobs 60   # 主选
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
