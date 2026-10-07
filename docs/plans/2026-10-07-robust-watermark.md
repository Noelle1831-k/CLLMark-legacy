# 利用全部编码空间的鲁棒水印：两个方案的设计与对比（v1，待用户审阅）

## 1. 动机与已测事实

- 现行方法（BCH(7,4) + 预期消息匹配）在每个单元只用 7 个位点；CodeNet 生成代码在节点粒度有 90–200 个可用位点（[v2 记录](../experiments/2026-10-07-codenet-v2.md)）。
- 未加水印的代码天然偏向某些码字：手写 JavaScript 84–96% 解码为 `0000`，其他语言最易误报的消息达 13–26%，未加水印的生成代码对某一消息达 28–61%。现行误报率取决于“选了哪个消息”。
- 位点按位置寻址（文件序 × 规则序，或标记后代码中的节点下标，并依赖嵌入时保存的支持文件）。删除、插入、重排代码会使位点错位。
- 规则间不独立（Python `init_list`/`list`）会让一次翻转改变两个读数。

用户要求：两个方案都要有难以破坏的水印锚点，考虑编码空间被人为破坏、跨消息误配（m′ 被当作 m），采用稳健的密码学构造，并在项目级代码上测试；消息长度 4 位与 8 位。

## 2. 共同框架

### 2.1 密钥与伪随机函数

- 密钥 K（32 字节）。PRF(K, x) = HMAC-SHA256(K, 域标签 ‖ x)，取所需位数。域标签区分用途（`white`、`role`、`seq`、`tag`），避免同一输出被复用。
- 实验中 K 由配置的 seed 派生（记入协议）；部署时 K 保密。没有 K，攻击者无法知道某位点的目标比特，也无法为任意 m 伪造通过检验的代码。
- 每个单元的消息 m 从 seed 与单元 ID 派生、在 2^k 中均匀抽取（不再固定为 `1010`），以消除“选中幸运消息”的偏差。报告同时按消息分组。

### 2.2 位点与锚点（位置无关寻址）

- **位点**：沿用 `cllmark/nodes.py` 的 `sites()`：每个规则对在每个文件中的每个可改写节点是一个位点，读数 0/1（两种样式都能改写时不可读）。嵌入用的位点必须 usable，且窗口互不重叠、互不相邻（沿用 `_Regions` 的语义）。
- **锚点键**：每个位点由“锚点上下文”的哈希寻址，与位置、文件名、支持文件无关。比较两种锚点：
  - **A-tok**：规则对名 + 所在函数名 + 位点节点内全部标识符与字面量的集合（字符串字面量按解码后的内容；排除规则自身引入或删除的名字，如 `printf/scanf/cout/cin/endl/std/list/dict/tuple/print/range/len/sum/Number/Math/Array/Object/parseInt/undefined/main/argc/argv`，按语言维护停用表）。抵抗格式、重排、我们自己的改写；改名会改变它。
  - **A-struct**：规则对名 + 位点节点的结构骨架：叶子按类别抽象（标识符 → `ID`，数值字面量保留，字符串按内容），运算符按规则族归类（比较、等式、复合赋值），可交换运算的子树排序后哈希。抵抗改名；但不同位置更容易撞键。
- **自稳定性检查**（分析阶段）：对每个位点，计算其两种读数下的键（单独改写该位点前后），以及在同一文件所有位点都改成随机目标后的键；键变化的位点标为不稳定，不参与嵌入和检测。目标：稳定位点 ≥ 90% 的 usable 位点（实测报告）。
- **去重成票**：键相同的多个位点构成一个“票”，嵌入时设为同一目标比特，检测时取其读数多数（平票不投票）。这样同一模式的重复代码不会被当作独立证据，二项分布的零假设才成立。
- **白化**：任何方案嵌入的比特都在 PRF(K, white, key) 之下异或白化。读数与 PRF 独立，因此未加水印的代码对任何消息的一致数都服从 Bin(n, 1/2)，与代码天然偏向何种形式无关。

### 2.3 嵌入

1. 在原代码上观察所有稳定、usable 位点及其键，按 2.2 的区域规则选出互不重叠的位点（先序贪心）。
2. 每个票的目标比特由方案给出（第 3 节）。读数与目标不同的位点按规则对分组，一遍改写（沿用 `nodes.place` 的逐对改写与跟随）。
3. 改写后重新观察：读数仍不等于目标的位点（规则间干扰），在下一轮单独改写；最多 4 轮。仍未设上的位点留下（检测时成为噪声票）。报告“设上率”。
4. 不保存支持文件。检测只需要 K、方案参数和待检代码。

### 2.4 检测（盲检测，只用 K）

1. 观察待检代码的所有可读位点，计算键并成票，得到每票读数 b(key)。
2. 只统计“已知键”之外的一切都无需对齐：被删的代码只减少票数；插入的代码贡献读数与 PRF 无关的随机票；重排和改名（A-struct）不影响键。
3. 判定按方案给出 p 值；给定显著性 α，p ≤ α 判为含水印。报告 α = 1e-3 与 1e-6 下的 TPR，以及全部 p 值的 ROC。

## 3. 两个方案

### 方案 1：嵌入 m（白化、重复），纠错位不嵌入，其余位点放 HMAC 标签

- 票按 role(key) = PRF(K, role, key) 分配：比例 ρ（默认 0.5）的票承载消息位，平均分给 k 个信息位（role 给出位序号 j）；其余票承载标签。
- 消息票目标：m_j ⊕ PRF(K, white, key)。标签票目标：PRF(K, tag, m ‖ key) ⊕ PRF(K, white, key)。
- **盲提取**：对每个信息位 j，对其所有票的 b(key) ⊕ white(key) 做多数表决，得到 m̂_j（平票记为不确定，m̂ 取两种取值并都检验，最多 4 个候选）。再对候选 m̂ 做标签检验：n_tag 票中与 PRF(K, tag, m̂ ‖ key) ⊕ white 一致的数 a，p = P[Bin(n_tag, 1/2) ≥ a]，乘以检验的候选数（Bonferroni）。
- **已知 m 的检验**：消息票与标签票一并与 m 的目标比较，p = P[Bin(n, 1/2) ≥ a]。
- **跨消息误配**：若 m̂ 某位错了（得到 m′），m′ 的标签与 m 的标签独立，标签一致数服从 Bin(n_tag, 1/2)，被拒绝的概率与随机代码相同。所以“只差一位就误配”的问题由标签消除。
- **纠错位**：按用户要求不嵌入。由于 m 的每位已经多次重复，再加 BCH 纠错位只是另一种冗余；需要时验证方可由 m 计算，但判定不依赖它。

### 方案 2：全部票放密钥序列 PRF(K, m, key)，阈值检验

- 每票目标：PRF(K, seq, m ‖ key) ⊕ PRF(K, white, key)。
- **已知 m**：a = 与目标一致的票数，p = P[Bin(n, 1/2) ≥ a]。
- **未知 m**：对 2^k 个消息逐一计算 p_m，取 m̂ = argmin，判定 p_min · 2^k ≤ α；同时报告最优与次优的差距 Δ = log10(p_次优) − log10(p_min)，Δ 小于 2 时记为“不确定”。
- **跨消息误配**：m′ ≠ m 的序列与 m 的序列独立，用 m′ 检验带 m 的代码，其一致数服从 Bin(n, 1/2)；误接受率等于 α（未知 m 时为 α，已含多重检验校正）。

### 基线

现行 BCH(7,4)，文件粒度与节点粒度，消息 4 位，按位置读取并依赖保存的支持文件（与现有代码完全一致）。在同一批攻击下比较。

## 4. 攻击（模拟攻击者没有 K、但知道公开规则集）

所有攻击用 seed 派生的随机数，确定可重放；对生成代码（含水印）和手写代码（零假设）都施加。

| 名称 | 参数 | 内容 |
|---|---|---|
| `flip` | p ∈ {0.1, 0.2, 0.3} | 随机选 p 比例的可读位点改成另一读数 |
| `normalize` | r ∈ {1, 3, all} | 随机选 r 个规则对，整文件统一改写为随机一侧的样式；`all` 为全部规则对 |
| `delete` | q ∈ {0.25, 0.5} | 随机删除 q 比例的顶层函数（项目级还随机删除 q 比例的文件） |
| `insert` | 1× | 在末尾追加等量的未加水印代码（同语言、另一题的手写解） |
| `rename` | — | 对文件内声明的局部变量、形参、函数名做一致改名（tree-sitter 查找声明并替换全部引用；跳过成员名、外部库名） |
| `reformat` | — | 去掉注释和空行；C/C++/JS 统一缩进与运算符两侧空白（Python 只去注释与空行） |
| `reorder` | — | 随机打乱顶层函数顺序（项目级还打乱文件名） |
| `combo` | — | rename + flip 0.2 + delete 0.25 |

`normalize all` 会把所有风格证据抹到随机水平：白化之后它等价于随机翻转一半的比特。这是基于公开规则集的风格水印的根本局限，两个方案和基线都无法抵抗，报告中如实给出，不作为通过条件。

攻击后的代码只用于检测（不要求能编译）；功能保持只在未受攻击的标记代码上测。

## 5. 评估矩阵与指标

- **语料**：
  - CodeNet：四种语言的生成组（嵌入，正例）与手写组（只检测，零假设）。
  - 项目级：`python_projects`、`c_projects`、`cpp_projects`（生成，正例，每个项目多文件，按项目汇总票）；`js_repos` 14 个仓库：作为手写零假设只检测；另设一个“功能压力”组，在其上嵌入并运行仓库自带测试，只用于功能保持，不进入检测统计。
- **变体**：方案 {1, 2} × 消息位数 {4, 8} × 锚点 {A-tok, A-struct}，全部为节点粒度位点；基线 BCH 文件/节点粒度，4 位。
- **指标**：
  - 容量：usable 位点、稳定位点、票数（去重后），按容量分段（<10、10–30、30–100、≥100）。
  - 嵌入：设上率、改动文件与行数、功能保持（CodeNet 用例、js_repos 测试）。
  - 检测：α = 1e-3、1e-6 下的 TPR（已知 m、未知 m 两种），ROC/AUC；盲提取的消息正确率；方案 1 的信息位多数表决正确率。
  - 零假设：手写组与攻击后的手写组在全部消息（4 位：16 个；8 位：256 个）上的经验误报率，与 α 比较（检验 p 值是否校准）；最大单消息误报率。
  - 跨消息：在标记代码上用全部错误消息 m′ 检验的误接受率。
  - 锚点：各攻击下检测时可读票中“键与嵌入时相同”的比例（锚点存活率）。
  - 每种攻击下的 TPR、盲提取正确率，以及随攻击强度的曲线。

## 6. 代码结构与分支

| 分支 | 文件 | 内容 |
|---|---|---|
| `claude/rw-core` | `cllmark/robust/{__init__,keys,anchors,embed,detect}.py`、`tests/test_robust_*.py` | PRF、锚点键、观察、嵌入、检测、两个方案的目标与判定 |
| `claude/rw-bench` | `benchmarks/robust_engine.py`、`benchmarks/attacks.py`、`benchmarks/config-rw-*.json`、`tools/robust_report.py`、`tests/test_robust_bench.py` | 评估引擎、攻击、配置、报告 |

两个分支并行，接口按 6.1 固定；rw-bench 在 rw-core 合并前用接口的最小假实现测试。合并顺序：rw-core → rw-bench → 实验记录，进入 `claude/robust-watermark`。

### 6.1 rw-core 接口（rw-bench 只依赖这些）

```python
@dataclass(frozen=True)
class Scheme:
    name: str            # "s1" | "s2"
    bits: int            # 4 | 8
    anchor: str          # "tok" | "struct"
    message_share: float = 0.5   # 方案 1 的 ρ

@dataclass(frozen=True)
class Observation:
    file: str; pair: str; index: int
    reading: int | None; usable: bool; stable: bool
    window: tuple[int, int]; key: str      # 锚点键（十六进制）

def observe(transformer, language, files: Mapping[str, str], anchor: str) -> list[Observation]: ...
def embed(transformer, language, files, scheme: Scheme, key: bytes, message: Sequence[int]) -> EmbedResult: ...
    # EmbedResult(written: dict[str, str], votes: int, targeted_sites: int, set_sites: int, rounds: int)
def detect(transformer, language, files, scheme: Scheme, key: bytes, message: Sequence[int] | None) -> Detection: ...
    # Detection(votes: int, agree: int | None, p_known: float | None,
    #           decoded: list[int] | None, p_blind: float, margin: float,
    #           per_file: dict[str, tuple[int, int | None]], keys: dict[str, int])   # keys: 键 -> 读数（用于锚点存活率）
def binomial_tail(n: int, a: int) -> float: ...   # P[Bin(n, 1/2) >= a]，精确计算（大 n 用对数）
```

### 6.2 rw-bench 的引擎约定

- 新配置键 `"robust": {"scheme": "s1|s2|bch-file|bch-node", "bits": 4|8, "anchor": "tok|struct", "alpha": [1e-3, 1e-6], "attacks": [...]}`，协议配置加入 `robust_engine.py`、`attacks.py` 与 `cllmark/robust/` 的摘要（仿照 `node_engine.protocol_config`），默认配置不受影响。
- 行字段与 `LegacyEngine` 兼容（`metrics.summarize_group` 能运行）：`marked_extraction.matched` = 已知 m 在 α=1e-3 下的判定，`original_extraction` 同理（零假设），`attacks[name].extraction` 同理；完整结果放在新字段 `robust`（每个攻击的 votes、agree、p_known、decoded、p_blind、margin、锚点存活率，以及零假设下全部消息的 p 值分布摘要）。
- 手写组沿用 `"embed": false` 的只检测路径；功能保持由现有 staged 功能阶段对 `marked` 目录运行。

## 7. 验收（实现阶段）

- 单元测试：PRF 与二项尾概率（与 `scipy` 无关的精确实现，对照小 n 的枚举）；锚点在自身改写下稳定；嵌入后在无攻击下 p_known ≤ 1e-6（容量 ≥ 30 时）；随机密钥下未加水印代码的 p 值近似均匀（KS 检验，在合成读数上）；方案 1 盲提取在无攻击下正确；跨消息误接受率在合成数据上 ≈ α。
- `make lint`、`make test`；服务器上 CodeNet 与项目级全部变体全量运行；默认 `make benchmark` 不变（协议指纹不变）；嵌入路径改动了代码，按 AGENTS.md 运行 `make repo-check`（嵌入函数加入真实仓库检查需另行评估，先不改 repo_check）。

## 8. 待用户确认

1. 方案 1 中消息票与标签票的比例 ρ 默认 0.5，是否需要多测 0.25/0.75？
2. 锚点 A-tok 与 A-struct 都测；若只能选一个作为主方案，倾向 A-struct（抵抗改名），代价是撞键更多、票数更少。
3. `normalize all` 不作为通过条件（任何基于公开规则集的风格水印都无法抵抗），只如实报告。
