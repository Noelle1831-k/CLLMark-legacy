# Claude Code 多 agent 团队：Opus 出方案，Sonnet 做实现

目标：把贵的 Opus 只用在"判断"上（定位根因、发现问题、定核心方案、终审），把实现和所有重复性工作交给 Sonnet，同时让调度本身也跑在 Sonnet 上。

## 方案一览

| 方案 | 适用场景 | 配置量 | 省用量程度 |
| --- | --- | --- | --- |
| A. `opusplan` 内置模式 | 单人、单线程任务，想零配置 | 一条命令 | 中 |
| B. 本仓库的 `/team` 团队（推荐） | 需要分析 + 多处实现 + 批量杂活 | 已就绪（`.claude/`） | 高 |
| C. 手写提示词 | 不想加文件、临时用一次 | 复制粘贴 | 中高 |

---

## A. 内置 `opusplan`（最简单）

```
/model opusplan
```

- 进入 Plan 模式（Shift+Tab 切换）时用 Opus 分析、写方案；批准方案退出 Plan 模式后自动切到 Sonnet 执行。
- 限制：只有一条上下文，Sonnet 执行时会继承 Opus 阶段读入的全部内容；不能并行，也没有独立终审。

可以用环境变量固定具体版本：

```bash
export ANTHROPIC_DEFAULT_OPUS_MODEL="claude-opus-5-5"
export ANTHROPIC_DEFAULT_SONNET_MODEL="claude-sonnet-5-5"
```

---

## B. `/team` 团队（本仓库已配置）

```
.claude/
├── settings.json            # 未指定模型的子 agent 默认用 sonnet
├── agents/
│   ├── architect.md         # Opus, effort high：只读分析，写方案到 .claude/plans/
│   ├── implementer.md       # Sonnet, effort medium：按方案实现 + 自检
│   ├── chore.md             # Sonnet, effort low：批量/机械任务、跑测试汇总
│   └── reviewer.md          # Opus, effort high：只看 diff 的一次性终审
└── skills/
    ├── team/SKILL.md        # /team：Sonnet 调度整个流程
    └── analyze/SKILL.md     # /analyze：只借用一次 Opus 分析
```

### 用法

```
/team 修复 watermark_extract.py 在 C++ 语料上 BCH 解码失败率偏高的问题
/analyze 为什么 folder_transform_check.py 对部分 Python 函数判定无可用规则
```

也可以在对话里直接点名：`让 architect 分析 X，然后用 implementer 实现`。

### 流程

```
用户 ──/team──▶ 调度者 (Sonnet)
                  │ 0. 分诊：机械任务→chore；小改动→implementer；其余走全流程
                  ▼
               architect (Opus) ──写──▶ .claude/plans/<slug>.md（结论/约束/任务 T1..Tn）
                  │  有待确认问题 → 先问用户 → SendMessage 回同一个 architect 修订
                  ▼
     ┌────────────┼────────────┐   互不依赖、文件不重叠的任务并行
 implementer   implementer    chore
   (Sonnet)     (Sonnet)     (Sonnet)
     │ BLOCKED → 调度者转给 architect 修订 → 原执行者继续
     ▼
 reviewer (Opus，按需，只看 git diff) → FIX_NEEDED → implementer 修
     ▼
 调度者：git diff --stat + 简短汇报
```

### 为什么省

1. **调度跑在 Sonnet 上**：`/team` 的 `model: sonnet` 让整个编排回合使用 Sonnet，即便主会话是 Opus。Opus 只在 architect / reviewer 子 agent 里出现。
2. **Opus 的上下文最小化**：architect 只读必要片段、只写一份方案文件、回复不超过 15 行；reviewer 只看 diff。
3. **传路径不传内容**：执行者自己读方案文件，调度者不重复粘贴，避免同一段文本在多个上下文里重复计费。
4. **返回格式强约束**：每个 agent 都有固定的短格式汇报，不回传 diff 和日志。
5. **SendMessage 续用 agent**：追问/修订时继续原 agent，复用其上下文和 prompt cache，而不是冷启动新 agent。
6. **分级 effort**：architect/reviewer `high`，implementer `medium`，chore `low`。
7. **按需终审**：小改动和纯机械改动跳过 Opus 终审。
8. **批量化**：chore 被要求用脚本/sed 批处理、只汇总测试结论。

### 可调项

- 想让终审也用 Sonnet：把 `reviewer.md` 的 `model` 改为 `sonnet`。
- 想更省：把 `chore.md` 改为 `model: haiku`（适合纯格式化、跑测试汇总）。
- 想让主会话默认就是 Sonnet：在 `.claude/settings.json` 加 `"model": "sonnet"`，需要时 `/analyze` 借用 Opus。
- 并行任务互相踩文件：给 `implementer.md` 加 `isolation: worktree`（每个执行者在独立 git worktree 中工作，合并由你处理）。
- 方案文件默认不入库（见 `.gitignore`）；想保留方案记录就删掉那一行。

---

## C. 不加文件，直接用提示词

在主会话（建议 `/model sonnet`）里粘贴：

```text
你是调度者，按以下团队流程完成任务，自己不做深度分析，也不亲手写实现：

1. 用 Agent 工具启动一个 general-purpose 子 agent，model 设为 "opus"，任务是：只读地分析下面的问题，
   定位根因并给出核心方案，把方案写到 .claude/plans/<slug>.md，包含"结论 / 约束与不变量 / 任务列表"，
   每个任务写明 kind(impl|chore)、files、depends、change、verify；最终回复不超过 15 行，不要修改源码。
2. 方案里有需要我确认的问题时先问我。
3. 对每个任务启动 model 为 "sonnet" 的 general-purpose 子 agent 实现：委派消息只给方案文件路径和任务 ID；
   互不依赖且文件不重叠的任务在同一条消息里并行发起；要求它自检后用不超过 10 行汇报
   STATUS/CHANGED/VERIFY，遇到方案与代码不符就报告 BLOCKED 而不是自行改方案。
4. 有 BLOCKED 时用 SendMessage 把原因发回第 1 步的 opus agent 修订方案，再让原执行者继续。
5. 改动超过约 50 行时，再启动一个 model 为 "opus" 的只读子 agent 只评审 git diff，只报阻断性问题；
   有问题交给 sonnet 执行者修复。
6. 最后 git diff --stat，给我简短汇报。不要提交。

任务：<在这里写任务>
```

---

## 相关文档

- 子 agent：https://code.claude.com/docs/en/sub-agents
- Skills：https://code.claude.com/docs/en/skills
- 模型配置（`opusplan`、环境变量）：https://code.claude.com/docs/en/model-config
