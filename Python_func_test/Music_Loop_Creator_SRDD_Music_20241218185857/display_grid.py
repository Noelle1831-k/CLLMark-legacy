def display_grid(self):
        '''
        Display the current state of the grid.
        '''
        for step in range(self.steps):
            row = [f"{self.grid[step][track] or '---'}" for track in range(self.tracks)]
            print(f"Step {step + 1}: {' | '.join(row)}")