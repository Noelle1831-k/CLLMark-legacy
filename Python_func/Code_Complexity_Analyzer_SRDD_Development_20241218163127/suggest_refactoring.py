def suggest_refactoring(self):
        suggestions = []
        if self.metrics['cyclomatic_complexity'] > 10:
            suggestions.append("Consider breaking down functions to reduce cyclomatic complexity.")
        if self.metrics['nesting_depth'] > 3:
            suggestions.append("Consider flattening nested structures to improve readability.")
        if self.metrics['code_duplication'] > 2:
            suggestions.append("Consider extracting repeated code into functions to reduce duplication.")
        for suggestion in suggestions:
            print(suggestion)