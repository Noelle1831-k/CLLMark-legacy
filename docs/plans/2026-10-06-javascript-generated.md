# JavaScript LLM 生成代码数据集方案

## v1

### 1. 目标

为 JavaScript 建立中长代码的 `role=generated` 语料（与 `exercism_js` 人类参考解配对，类似 MBPP_H / MBPP_G），在用户的数据集仓库 `Noelle1831-k/dataset`（私有）上扩展，并导出供 CLLMark 接入。生成与验证工作尽量交给火山方舟 API 与脚本完成，代理自身只做脚本编写、抽检与汇总（节省 Claude 用量）。

### 2. 模型与接口

- 密钥：`~/.config/cllmark/ark.env`（`ARK_API_KEY=…`，权限 600）。脚本通过环境变量读取；**不得**打印、写入日志、提交到任何仓库或写进代码。
- 接口（OpenAI 兼容，`openai` Python 包）：
  - `https://ark.cn-beijing.volces.com/api/v3`：模型 `deepseek-v4-1-flash-260910`、`glm-5-3-flash-260828`
  - `https://ark.cn-beijing.volces.com/api/coding/v3`：模型 `DeepSeek-V4.1-Flash`、`GLM-5.3-Flash`
  - 先用一个极小请求探测两种接口与 `chat.completions` / `responses` 哪种可用；生成时每个模型使用一个主接口，失败或限流时退回另一个接口，并在元数据中记录实际接口。不开启 web_search 等工具。
- 在数据集仓库中新建独立虚拟环境安装 `openai`；**不要**向 `/Users/bytedance/Downloads/data/data/.venv-benchmark` 安装任何包（其环境指纹属于实验协议）。

### 3. 任务来源

- Exercism JavaScript 练习（MIT）。固定 commit：先查找 `/Users/bytedance/Downloads/data/data/.claude/worktrees/agent-*/benchmarks/javascript.lock.json` 中 exercism 的 commit（另一个代理正在接入同一题库）；若尚不存在，取 `exercism/javascript` 当前 main 的 commit 并记录，主会话之后统一。
- 题目范围：`exercises/practice/*` 中参考解（`.meta/proof.ci.js`）≥ 20 行的题；同时标记属于 Aider Polyglot 子集的题。
- 提示词（Aider Polyglot 风格）：题目 `instructions.md`（及 `.docs/instructions.append.md` 若有）+ 题目存根文件 `<slug>.js` 的内容，要求模型给出完整的 `<slug>.js` 文件内容（ES 模块、保留导出名），只输出代码块。**不得**把参考解或测试文件放进提示词。提示词模板固定并保存在仓库中。
- 采样：每题每模型 3 个样本（temperature 0.8、top_p 0.95，另加 1 个 temperature 0 样本），最大输出长度足够容纳完整文件。

### 4. 验证与清洗

- 用固定版本 Jest（按 Exercism 仓库 lockfile，`npm ci --ignore-scripts`）在检出副本中把生成代码写入 `<slug>.js`，去掉 `xtest`/`skip` 后运行该题 spec，记录通过/失败/超时与测试日志摘要。不通过的样本保留并标记（它们仍可用于水印度量，只是不进入配对效用比较）。
- 清洗：从回复中提取代码块（记录提取方式），丢弃空输出或无法解析的输出（用 Node `--check`），对规范化后完全相同的样本去重（保留首个并记录重复数），标记包含参考解大段原文（如与 proof.ci.js 的最长公共子串 > 80% 行）的样本。
- 统计：每模型通过率、代码行数分布（中位数、P90）、与参考解的行数比。

### 5. 数据集仓库中的组织

- 克隆到 `/Users/bytedance/Downloads/data/dataset-js`（`gh repo clone Noelle1831-k/dataset`），新建分支 `javascript-exercism-generated`。先阅读该仓库的 `AGENTS.md`、`README.md` 与现有目录约定（gen、judge、oracles、problems、solutions、metadata、export 等），按其约定放置题目、生成脚本、提示词、原始回复、清洗后样本、判题结果与导出文件；约定与本方案冲突时以该仓库约定为准并说明。
- 每个样本的元数据至少包括：题目 slug、Exercism commit、模型、接口、请求参数、提示词摘要、响应 id、token 用量、生成时间、提取方式、判题结果、去重/泄漏标记。
- 导出：`export/` 下（或该仓库约定位置）提供 CLLMark 可直接导入的 JSONL：每行 `{task_id, slug, model, sample, temperature, code, passed, exercism_commit, ...}`，并附人类参考解 JSONL（同一 commit）。
- 只在本地分支提交，**不要推送**（推送由主会话征得用户同意后进行）。

### 6. 节省用量

- 生成、判题、统计全部由脚本批量完成（并发 4–8，指数退避重试，断点续跑：已完成的请求不重发）；代理不要逐个阅读生成结果，只看汇总与少量抽样（≤ 5 个）。
- 回复主会话 ≤ 30 行。

### 7. 禁止事项

- 不修改 CLLMark 仓库与其工作树（只读取锁文件）；不运行 CLLMark 的 benchmark/baseline。
- 不调用方案以外的模型或付费服务；不开启联网搜索工具。
- 不提交密钥、原始 HTTP 头或含密钥的日志。
