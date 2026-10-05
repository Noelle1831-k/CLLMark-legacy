def analyze_code(self, source_files):
        complexity = 0
        for file in source_files:
            complexity = complexity + self.calculate_cyclomatic_complexity(file)
        return complexity