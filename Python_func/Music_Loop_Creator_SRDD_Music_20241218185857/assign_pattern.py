def assign_pattern(self, pattern):
        '''
        Assigns a pattern to the grid.
        '''
        for i, note in enumerate(pattern.notes):
            step = i % self.steps
            track = i // self.steps
            if track < self.tracks:
                self.grid[step][track] = note