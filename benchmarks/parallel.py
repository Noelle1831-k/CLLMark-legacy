"""Shared sizing of the parallel stages of the loop."""

import os


def worker_count():
    """Every hardware thread."""
    return os.cpu_count() or 1
