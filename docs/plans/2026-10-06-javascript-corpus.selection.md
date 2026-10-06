# JavaScript 语料：候选仓库评估与入选表

对应方案 [2026-10-06-javascript-corpus.md](2026-10-06-javascript-corpus.md)；规模与容量分布见 [inventory.tsv](2026-10-06-javascript-corpus.inventory.tsv)。
“源码 LOC”为锁文件 glob 选中的手写源文件物理行数（空文件除外，不含 test、dist、生成与压缩文件）。“干净测试”为干净检出副本上的单次串行时间，括号内为 8 个副本同时运行的最长时间与失败数（`tools/setup_javascript.py --stress 8`；Node v24.18.0，机器同时运行其他任务，时间偏大）。

## 1. 仓库评估（按方案顺序评估，另加两个替补）

| 仓库 | tag | commit | 许可证 | 源码 LOC | ≥80 行文件 | 测试运行器 | 干净测试 s（8 并发） | 结论 | 原因 |
| --- | --- | --- | --- | ---: | ---: | --- | --- | --- | --- |
| express | v4.22.3 | `899b52494e74` | MIT | 4152 | 9 | mocha 6 | 2.21 (4.9 s，1/8 failed) | 入选 | 满足；测试绑定套接字，8 个同类副本并发时 1/8 failed（ws 的测试固定监听 1337；express/body-parser 为临时端口冲突，表现为 404/ECONNRESET），故在 config.json 标记 `exclusive`，由全局文件锁串行化 |
| ws | 8.22.0 | `297202cdae9b` | MIT | 4960 | 10 | mocha 8 | 2.11 (2.5 s，1/8 failed) | 入选 | 满足；测试绑定套接字，8 个同类副本并发时 1/8 failed（ws 的测试固定监听 1337；express/body-parser 为临时端口冲突，表现为 404/ECONNRESET），故在 config.json 标记 `exclusive`，由全局文件锁串行化 |
| semver | v7.8.5 | `6e05b7637396` | ISC | 2648 | 8 | tap 16 | 5.34 (13.7 s，0/8) | 入选 | 满足；`tap --no-coverage -j2`；锁文件由 npm 解析生成（仓库 `.npmrc` 设 `package-lock=false`） |
| qs | v6.16.0 | `bb9379e01fad` | BSD-3-Clause | 1213 | 3 | tape | 0.66 (0.7 s，0/8) | 入选 | 全部条件满足 |
| commander | v12.1.0 | `970ecae402b2` | MIT | 3672 | 5 | jest 29 (JS tests only) | 4.99 (14.7 s，0/8) | 入选 | 满足；只运行 JS 测试（`.ts` 类型测试经 ts-jest，不在其内）；复制检出需保留符号链接（已修复） |
| body-parser | 1.20.8 | `5c08c2008eac` | MIT | 1141 | 6 | mocha 10 | 1.2 (1.5 s，1/8 failed) | 入选 | 满足；测试绑定套接字，8 个同类副本并发时 1/8 failed（ws 的测试固定监听 1337；express/body-parser 为临时端口冲突，表现为 404/ECONNRESET），故在 config.json 标记 `exclusive`，由全局文件锁串行化 |
| markdown-it | 14.3.2 | `efb9993124c3` | MIT | 6224 | 28 | node:test | 2.11 (6.6 s，0/8) | 入选 | 满足；源文件为 `.mjs`（ESM），测试为 `node:test`；cohort 增加 `extensions`，`npm test` 中的 lint/build 步骤不运行 |
| argparse | 2.0.1 | `e373563876f1` | Python-2.0 | 4214 | 2 | mocha 8 | 1.2 | 淘汰 | 许可证 Python-2.0 不在 MIT/ISC/BSD/Apache-2.0 之内（测试 1614 项全部通过，但条件不满足） |
| pako | 2.2.0 | `c743a323fb7d` | MIT AND Zlib | 6905 | 8 | node:test | 0.7 | 淘汰 | 许可证为 MIT AND Zlib，Zlib 不在允许列表（测试 227 项全部通过） |
| fast-xml-parser | v4.5.7 | `49a12f10e9a4` | MIT | 2500 | 8 | jasmine 3 | 3.27 (3.3 s，0/8) | 入选 | 满足；排除未被测试加载的 `src/cli`、`src/v5` 与空文件 `prettifyJs2Xml.js`（共 28 个文件，约 2,100 行），避免空洞的 oracle |
| decimal.js | v10.6.0 | `1a6e845004b2` | MIT | 4951 | 1 | custom node script (wrapped) | 1.16 (1.5 s，0/8) | 入选 | 满足；测试脚本总是退出 0，命令用包装器按“N of N tests passed”判定；单文件库（`.mjs` 为生成副本，排除） |
| bignumber.js | v9.3.1 | `a7bc1f175c1e` | MIT | 2922 | 1 | custom node script (wrapped) | 0.84 (0.9 s，0/8) | 入选 | 满足；测试脚本总是退出 0，命令用包装器按“N of N tests passed”判定；单文件库（`.mjs` 为生成副本，排除） |
| escodegen | v2.1.0 | `899cfdf5dc99` | BSD-2-Clause | 2667 | 1 | mocha | 1.46 (2.9 s，0/8) | 入选 | 全部条件满足 |
| ajv | 6.15.0 | `184bc32745d9` | MIT | 2028（不含生成的 lib/dotjs） | 7 | mocha 8 | 失败 | 淘汰 | 测试需要先运行 `npm run build`（compile-dots 生成 lib/dotjs/*.js），否则 `Cannot find module ../dotjs/validate`；JSON-Schema-Test-Suite 是未随 tarball 提供的子模块。需要构建步骤，违反条件 |
| debug | 4.4.3 | `6b2c5fbdb7d4` | MIT | 837 | 3 | mocha 5 | 0.3 | 淘汰 | 源码 837 行，低于 1,000 行下限（测试通过） |
| lodash | 4.17.21 | `f299b52f3948` | MIT | 17209 | 1 | custom QUnit script | 9.66 (10.0 s，0/8) | 入选 | 满足（方案指定 4.17.21，非 4.x 最新 4.18.1）；单个 17,209 行文件，干净测试 ~10 s；单元耗时见开放问题 |
| ejs | v3.1.10 | `d3f807dea9ce` | Apache-2.0 | 1202 | 2 | mocha (tdd) | 1.16 (2.0 s，0/8) | 入选（替补） | 替补候选，全部条件满足；用于在 lodash 因单元耗时被取消时仍保持 ≥ 12 个 |
| bn.js | v5.2.5 | `eb2e57c4e50a` | MIT | 3564 | 1 | mocha | 0.67 (0.4 s，0/8) | 入选（替补） | 替补候选，全部条件满足；用于在 lodash 因单元耗时被取消时仍保持 ≥ 12 个 |

入选 14 个（方案候选 12 个 + 替补 ejs、bn.js）；淘汰 4 个：argparse、pako、debug、ajv。方案中的主要线（express 4.x 等）取各自主版本内最新稳定 tag（commander 为 12.x 的 12.1.0，非最新主版本）。

## 2. Exercism JavaScript

- 来源 exercism/javascript（MIT），固定到 `main` 的 `65a60cac2145e8c6549de39e807753e577a02f8d`（2026-10-02），tarball sha256 `91c8c42a9e5c5c18…`；依赖由仓库 `pnpm-lock.yaml` 经 `pnpm install --frozen-lockfile --ignore-scripts` 安装（pnpm 11.24.0）。
- practice 练习 139 个；参考解 ≥ 20 行的 100 个全部通过各自的 Jest spec（0 个因测试失败被排除）；排除 39 个，原因均为参考解少于 20 行（见 `dataset/Jsonl/exercism_javascript_excluded.jsonl`）。所有练习都是单参考解/单 spec 文件。
- 参考解行数分布：中位数 49.0，P90 113，最小 20，最大 194。
- Aider Polyglot（`Aider-AI/polyglot-benchmark` 固定 `7e0611e77b54`，JavaScript 49 题）：与入选的 100 题重合 45 题；其余 4 题（binary、pig-latin、sum-of-multiples、transpose）的参考解不足 20 行。
- Jest 单题时间（4 线程并行下的干净运行，含 Babel 转换）：中位数 1.2 s，P90 2.5 s，最大 5.2 s。
- 与方案的差异：Exercism CI 只启用 `xtest/xit/xdescribe`，**不**取消 `test.skip`/`describe.skip`（有意长期跳过的用例；5 个练习含 `.skip`）。oracle 沿用 CI 的做法，故这些用例保持跳过。

## 3. 语料规模（全量清单）

| 组 | 单元 | 行数中位数 | 行数 P90 | 容量中位数 | 可嵌入（容量 ≥ 7） |
| --- | ---: | ---: | ---: | ---: | --- |
| js_repos | 14 | 3243.0 | 6224 | 55.5 | 14/14 (100.0%) |
| js_repo_files | 84 | 221.5 | 952 | 11.0 | 73/84 (86.9%) |
| exercism_js | 100 | 49.0 | 113 | 6.0 | 41/100 (41.0%) |
| js_projects | 4 | 268.5 | 3908 | 10.5 | 4/4 (100.0%) |
| mbjsp_generated | 112 | 8.0 | 16 | 3.0 | 5/112 (4.5%) |
| mbjsp_human | 938 | 8.0 | 15 | 2.0 | 7/938 (0.7%) |

容量由当前检出的规则集测得（含另一代理正在修改的 `javascript/rules.py` 的当时版本），随规则改动而变化。

## 4. 生成代码来源调研（只调研，未下载、未接入、未调用任何模型）

目标：为 `role=generated` 的 JavaScript 中长代码寻找可复现的公开 LLM 输出。结论：**没有找到“中长、公开、带测试、LLM 生成的 JavaScript 补全”开箱可用的来源**；可行路线是用已固定的模型 API 为 Exercism/仓库文件生成（需要用户决定），或使用下表中的公开数据。

| 来源 | 许可 | 规模（JavaScript） | 代码长度 | 带测试 | 固定方式 | 评价 |
| --- | --- | --- | --- | --- | --- | --- |
| MultiPL-E（`nuprl/MultiPL-E`，HF；GitHub 同名） | HF 标 MIT（GitHub 为 NOASSERTION） | humaneval-js 161、mbpp-js 397 题（仅题目与测试，非补全） | 函数级，几行到几十行（与 MBJSP 同级） | 是 | HF 数据集修订号 / GitHub 提交 `3025a531…` | 题目侧可用，长度不满足“中长” |
| MultiPL-E completions（`nuprl/MultiPL-E-completions`，HF） | 卡片未声明 | 100K–1M 条记录（跨语言和模型，各拆分 43–161 条）；含 JavaScript 配置需确认 | 函数级短补全，附执行结果 | 是（tests 字段） | HF 修订号 | 真正的公开模型输出（SantaCoder/StarCoder 论文），模型较旧；许可不明需先确认 |
| HumanEval-X（`zai-org/humaneval-x`，HF） | Apache-2.0 | JS 164 题（共 820 条跨语言） | 函数级，短 | 是（含标准解与测试） | HF 修订号 | 只有参考解，无 LLM 输出 |
| McEval（`Multilingual-Multimodal-NLP/McEval`，HF） | CC-BY-SA-4.0（相同方式共享，需评估对本仓库的约束） | JavaScript 在 generation/explanation/completion 各任务中均有；每语言题数未在元数据中给出 | 函数级，短到中等 | 是 | HF 修订号（2024-11-20 更新） | 题目与参考，非模型输出 |
| Aider Polyglot（`Aider-AI/polyglot-benchmark`，Apache-2.0 为主仓库 aider） | 题库为 Exercism（MIT）；该仓库自身未声明许可 | JavaScript 49 题（与本方案 Exercism 语料重合 45 题） | 参考解 20–200 行，即中等长度 | 是（Jest spec） | 提交 `7e0611e7…` | 公开的只有排行榜汇总（aider 仓库 `aider/website/_data/*.yml`：通过率、成本、命令），**没有逐题的模型代码输出**；需要自己运行 aider 才能得到生成代码 |
| Multi-SWE-bench（`ByteDance-Seed/Multi-SWE-bench`，HF） | “Other”（需读取卡片条款） | 1,632 个实例跨 7 种语言；JavaScript 6 个项目、TypeScript 3 个项目 | 补丁级（真实仓库修改） | 是（项目测试） | HF 修订号（2026-07 更新） | 与本方案的 `js_repo_files` 思路接近，但需要 Docker 环境，且元数据未说明是否包含各模型的预测补丁 |
| ProjectTest（2025，论文基准） | 未核实 | 20 个中型 JavaScript 项目（面向单元测试生成） | 项目级 | 是 | 论文/仓库 | 目标是生成测试而非生成源码，仅作仓库来源参考 |

建议（由主会话与用户决定）：(a) 用已固定的模型对 Exercism 题的 spec 生成解答（每题可得 20–200 行的 generated 样本，oracle 已就绪，Aider Polyglot 重合 45 题便于与公开排行榜对照），并保存提示、模型 ID、温度和原始输出；(b) 确认 MultiPL-E completions 的许可与 JavaScript 配置后，作为“旧模型、短函数”的对照；(c) McEval 的 CC-BY-SA-4.0 需要先判断是否允许作为语料入库。

## 5. 与方案的偏差

- 测试命令保存在 `config.json` 的 `projects`（沿用已有小项目的约定并参与协议指纹），锁文件不重复保存，由测试核对每个仓库都有命令。
- 多入选 2 个替补仓库（ejs、bn.js）；方案候选中 ajv 6、debug、argparse、pako 被淘汰。
- `js_repos`/`js_repo_files` 的 `.mjs` 通过新增 cohort 选项 `extensions` 支持（markdown-it）。
- 为避免并发伪 FAIL 增加 `exclusive` 套接字锁；为 commander 的符号链接夹具把复制检出改为保留符号链接；覆盖写入前移除符号链接。
- Exercism 的 `.skip` 用例保持跳过（见上）。
