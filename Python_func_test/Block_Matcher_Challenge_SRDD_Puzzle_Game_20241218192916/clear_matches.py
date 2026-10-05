def clear_matches(self):
        matches = self.find_matches()
        for x, y in matches:
            self.grid[x][y] = None
        self.drop_blocks()