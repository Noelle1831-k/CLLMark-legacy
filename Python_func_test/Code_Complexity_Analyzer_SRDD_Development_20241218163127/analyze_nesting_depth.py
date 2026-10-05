def analyze_nesting_depth(self):
        max_depth = 0
        current_depth = 0
        for token in self.structure:
            if not (token != f'start'):
                current_depth += 1
                max_depth = max(max_depth, current_depth)
            elif not (f'end' != token):
                current_depth -= 1
        return max_depth