# JavaScript 语料扩充方案：真实中型仓库与 LLM 基准

## v1

### 1. 目标与动机

MBJSP 每个单元只有一个短函数（冒烟中容量最大 7，可嵌入约 1%），无法体现规则在真实代码上的适用面、语义风险与效用保持；现有 `js_projects` 只有 4 个小库、每库 1 个单元，统计意义不足。用户要求改用多个真实中型 GitHub JavaScript 仓库与较新的 JavaScript LLM 测试数据集。

新增三类 cohort（MBJSP 与现有 4 个小库保留，作为对照，不删除）：

| cohort | 单元 | 角色 | oracle |
| --- | --- | --- | --- |
| `js_repos` | 每个仓库 1 个单元（项目级水印，码位分布在多个文件） | human | 仓库自带测试套件 |
| `js_repo_files` | 每个仓库中每个 ≥ 80 行的源文件 1 个单元（单文件水印） | human | 同一仓库测试套件（只覆盖该文件） |
| `exercism_js` | Exercism JavaScript 练习的参考解（Aider Polyglot 基准所用题库），每题 1 个单元 | human | 该题的 Jest 测试 |

属于语料与评估协议改动（数据集指纹变化）。`cllmark-3` 尚无参考运行，因此不需要改协议版本号；最终全量运行将作为 `cllmark-3` 的首个参考。

### 2. 仓库选择

#### 2.1 候选（按此顺序评估，选出 ≥ 12 个通过 2.2 全部条件的仓库）

express 4.x、ws 8.x、node-semver 7.x、qs 6.x、commander 12.x、body-parser 1.x、markdown-it 14.x、argparse 2.x、pako 2.x、fast-xml-parser 4.x、decimal.js 10.x、bignumber.js 9.x、escodegen 2.x、ajv 6.x、debug 4.x、lodash 4.17.21（lodash.js 单文件约 17k 行，测试时间若超限则排除）。可以替换为其他满足条件的仓库，但要说明理由。

#### 2.2 条件（全部满足）

- 许可证为 MIT / ISC / BSD / Apache-2.0；仓库仍公开可下载；选最新稳定 tag，固定到 commit。
- 源码是手写 JavaScript（`.js`/`.cjs`/`.mjs`），测试直接加载这些源文件（不经过 TypeScript、Babel、rollup 等构建步骤；若测试只针对构建产物则排除）。
- 被测源码（不含 test、dist、vendor、examples、benchmark、生成文件、压缩文件）总计 1,000–20,000 行。
- 在 Node v24 上 `npm ci --ignore-scripts`（有 lockfile 时）或固定版本的 `npm install --ignore-scripts` 后，干净检出的测试套件全部通过，且在 8 个并发任务下单次运行 ≤ 60 秒（`project_test_timeout_seconds` 为 120）。若少数测试本身不稳定或依赖网络，可在测试命令中排除这些文件，并逐个记录原因。
- 测试不访问网络，不需要浏览器。

### 3. Exercism JavaScript

- 来源 `exercism/javascript`（MIT），固定到最新 commit。Aider Polyglot 基准的 JavaScript 部分即取自该题库；记录其中哪些题属于 Aider Polyglot 子集（若能从公开的 `Aider-AI/polyglot-benchmark` 仓库得到列表，同样固定 commit）。
- 单元 = `exercises/practice/<slug>/.meta/proof.ci.js`（参考解）；测试 = 同目录 `<slug>.spec.js`（去掉 `xtest`/`test.skip` 的跳过标记，按 Exercism CI 的做法全部运行）。
- 只保留参考解 ≥ 20 行的题，并记录行数分布。
- oracle：在缓存中的固定检出副本里，把单元代码写入 `<slug>.js`，用固定版本的 Jest（按该仓库 package.json/lockfile 安装）只运行该题的 spec。干净参考解必须全部通过；不通过的题记录原因并排除（排除发生在建立语料时，不是在实验中删除样本）。

### 4. 生成代码（只调研，不实现）

为 `role=generated` 的 JavaScript 中长代码寻找可复现、公开的 LLM 输出来源（例如 MultiPL-E 公开补全、McEval、Aider Polyglot 公开输出等），列出：名称、许可、规模、代码长度分布、是否带测试、固定方式。不要下载或接入，也不要调用任何模型 API；由主会话与用户决定。

### 5. 接入实现

- `benchmarks/javascript.lock.json`：每个仓库增加 repository、tag、commit、tarball sha256、license、源码 globs、排除 globs、测试命令、依赖安装方式；Exercism 同样固定。
- `tools/setup_javascript.py`（`make setup-javascript`）：按 commit 下载 GitHub tarball（`https://codeload.github.com/<owner>/<repo>/tar.gz/<commit>`），校验 sha256，解压到 `.benchmark-cache/js-projects/<name>`，`--ignore-scripts` 安装依赖，跑一次干净测试并记录耗时；幂等。
- 语料：把选中的源文件复制到新的 `dataset/JS_repos/<name>/`（保持相对路径），Exercism 参考解与题目元数据写入 `dataset/Jsonl/exercism_javascript.jsonl`（或 `dataset/Exercism_JS/` 目录，按现有 MBJSP 的组织方式选择更一致的一种）。只新增，不修改已有语料。
- `benchmarks/common.py` / `benchmarks/utility.py`：
  - `js_repos`：沿用现有 `project_tests` oracle（复制检出、链接 node_modules、覆盖单元文件、运行测试命令）。
  - `js_repo_files`：新增单元级别（例如 `level: "project_file"`），单元 = 单个文件，水印只在该文件内嵌入；oracle 复用 `project_tests`，覆盖该文件到仓库中的原相对路径。清单阶段按 2.2 的源文件规则与 ≥ 80 行过滤，过滤规则写在配置中，结果可复现。
  - `exercism_js`：新增 oracle `exercism`（见第 3 节）。缓存键包含单元代码摘要与 oracle 实现摘要，与现有缓存机制一致。
  - 失败证据（stdout/stderr）保存在单元目录中（沿用 S3 的修正）。
- `benchmarks/config.json`：新增三个 cohort 与项目测试命令；`jobs`、超时等全局参数不变。
- 测试：`tests/test_research_loop.py` 增加 `project_file` 清单与 oracle、`exercism` oracle 的测试（使用一个小型本地夹具，不依赖网络）。
- 文档：`README.md`、`docs/RESEARCH_LOOP.md`、`docs/CODE_MAP.md` 中的 cohort 说明与设置步骤。

### 6. 验证（不运行全量）

- `make setup-javascript` 两次（第二次应无下载、无改动）。
- `.venv-benchmark/bin/python -m unittest discover -s tests -v` 全部通过。
- 只对新 cohort 运行一次冒烟：`tools/research_loop.py loop --limit 5 --cohort js_repos --cohort js_repo_files --cohort exercism_js`（先确认参数），检查：0 框架错误；干净代码 oracle 全部通过；水印嵌入/提取有结果；单元耗时分布与全量运行时间估计。
- 统计每个新 cohort 的单元数、代码行数分布（中位数、P90）、容量分布（可嵌入比例），写入 `docs/plans/2026-10-06-javascript-corpus.inventory.tsv`。

### 7. 禁止事项与边界

- 下载只限于第 2、3 节选中的固定版本源码与其依赖；`npm` 一律 `--ignore-scripts`；不运行仓库中的任意安装脚本或构建脚本。
- 不修改已有语料（`dataset/` 已有内容、`*_func`）、`benchmarks/baselines/`、门禁阈值、度量实现（metrics.py 的计算方式）；不修改规则文件（`javascript/rules.py` 等，另一个代理正在修改）。
- 不运行 `make benchmark`、`make baseline`、`tools/research_loop.py baseline`。
