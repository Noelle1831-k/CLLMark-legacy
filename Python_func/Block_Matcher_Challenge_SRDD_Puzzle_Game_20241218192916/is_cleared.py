def is_cleared(self):
        return all(self.grid[x][y] is None for x in range(self.size) for y in range(self.size))