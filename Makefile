BENCH_PYTHON ?= .venv-benchmark/bin/python

.PHONY: corpus setup-benchmark setup-javascript doctor inventory test smoke benchmark baseline watch-benchmark code-map

corpus:
	git submodule update --init corpus

setup-benchmark:
	python3 tools/setup_benchmark.py

setup-javascript:
	$(BENCH_PYTHON) tools/setup_javascript.py

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
