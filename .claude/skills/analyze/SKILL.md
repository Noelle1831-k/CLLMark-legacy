---
name: analyze
description: 单独调用 Opus 架构师做一次分析（定位问题/给出方案），结果写入 .claude/plans/，不做实现。适合在便宜模型的主会话里临时借用 Opus 的判断力。
argument-hint: <要分析的问题或目标>
disable-model-invocation: true
context: fork
agent: architect
background: false
---

分析以下问题，找出根因或给出核心方案，并按你的约定把方案写入 `.claude/plans/<slug>.md`：

$ARGUMENTS

如果信息不足以下结论，列出最关键的待确认问题，而不是猜测。
