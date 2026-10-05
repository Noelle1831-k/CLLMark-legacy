BENCH_PYTHON ?= .venv-benchmark/bin/python

.PHONY: setup-benchmark doctor inventory test smoke benchmark baseline watch-benchmark code-map

setup-benchmark:
	python3 tools/setup_benchmark.py

doctor:
	$(BENCH_PYTHON) tools/research_loop.py doctor

inventory:
	$(BENCH_PYTHON) tools/research_loop.py inventory

test:
	$(BENCH_PYTHON) -m unittest discover -s tests -v

smoke: code-map
	$(BENCH_PYTHON) tools/research_loop.py loop --limit 2

benchmark: code-map
	$(BENCH_PYTHON) tools/research_loop.py loop

baseline: code-map
	$(BENCH_PYTHON) tools/research_loop.py loop --initialize-baseline

watch-benchmark:
	$(BENCH_PYTHON) tools/research_loop.py watch

code-map:
	python3 tools/build_code_index.py
