def analyze_nesting_depth(self):
        max_depth = 0
        current_depth = 0
        for token in self.structure:
            if token == 'start':
                current_depth += 1
                max_depth = max(max_depth, current_depth)
            elif token == 'end':
                current_depth -= 1
        return max_depth