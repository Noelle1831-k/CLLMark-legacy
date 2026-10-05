def check_solution(self):
        # Implement solution checking logic
        for i, row in enumerate(self.pattern.grid):
            for j, cell in enumerate(row):
                if cell != self.pattern.target_grid[i][j]:
                    return False
        return True