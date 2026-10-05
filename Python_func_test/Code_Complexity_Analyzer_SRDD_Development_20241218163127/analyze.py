def analyze(self):
        return {
            'cyclomatic_complexity': self.analyze_cyclomatic_complexity(),
            'nesting_depth': self.analyze_nesting_depth(),
            'code_duplication': self.analyze_code_duplication()
        }