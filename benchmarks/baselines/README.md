# 固定参考结果

`current.json` 是本机完整运行的紧凑参考，包含语料、协议和环境摘要、各组指标以及失败 ID。完整源码副本、输入和日志保存在其 `baseline_record.local_run_directory` 指向的本地实验目录中，未上传到 Git。

它记录旧算法的实际效果，可以包含算法本身的已知失败。新版本不应新增功能回退或丢失覆盖；提升基线不能用来掩盖失败。参考的更新必须显式执行，旧记录自动保存到 `history/`。

环境摘要包含 Python 版本和路径、编译器、依赖与解析库。更换机器、目录或运行环境后，原参考可能不可比。为新环境建立独立参考：

```bash
.venv-benchmark/bin/python tools/research_loop.py loop \
  --baseline benchmarks/baselines/my-environment.json --initialize-baseline
.venv-benchmark/bin/python tools/research_loop.py loop \
  --baseline benchmarks/baselines/my-environment.json
```

第一条仅在目标参考文件不存在时执行；日常重跑使用第二条。seed、水印、语料或度量协议变化也应独立记录参考，详见 [科研循环说明](../../docs/RESEARCH_LOOP.md)。
