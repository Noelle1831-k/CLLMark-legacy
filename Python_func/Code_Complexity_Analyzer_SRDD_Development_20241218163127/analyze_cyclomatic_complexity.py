def analyze_cyclomatic_complexity(self):
        complexity = 1
        for token in self.tokens:
            if token in ['if', 'for', 'while', 'and', 'or']:
                complexity += 1
        return complexity