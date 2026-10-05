def swap_blocks(self, x1, y1, x2, y2):
        if self.is_adjacent(x1, y1, x2, y2):
            self.grid[x1][y1], self.grid[x2][y2] = self.grid[x2][y2], self.grid[x1][y1]
            if not self.find_matches():
                # Swap back if no match is created
                self.grid[x1][y1], self.grid[x2][y2] = self.grid[x2][y2], self.grid[x1][y1]