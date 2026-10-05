def compare_to_benchmark(self, benchmark):
        return [p - b for p, b in zip(self.performance, benchmark)]