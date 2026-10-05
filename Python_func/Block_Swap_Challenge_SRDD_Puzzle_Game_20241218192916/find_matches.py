def find_matches(self):
        matches = set()
        # Check for horizontal matches
        for y in range(self.size):
            for x in range(self.size - self.match_length + 1):
                if self.grid[x][y].is_match(self.grid[x + 1][y]) and self.grid[x][y].is_match(self.grid[x + 2][y]):
                    matches.update({(x, y), (x + 1, y), (x + 2, y)})
        # Check for vertical matches
        for x in range(self.size):
            for y in range(self.size - self.match_length + 1):
                if self.grid[x][y].is_match(self.grid[x][y + 1]) and self.grid[x][y].is_match(self.grid[x][y + 2]):
                    matches.update({(x, y), (x, y + 1), (x, y + 2)})
        return matches