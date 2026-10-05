def matches_target(self, target_shape):
        for i, row in enumerate(target_shape):
            for j, cell in enumerate(row):
                if cell and self.grid[i][j] != cell:
                    return False
        return True