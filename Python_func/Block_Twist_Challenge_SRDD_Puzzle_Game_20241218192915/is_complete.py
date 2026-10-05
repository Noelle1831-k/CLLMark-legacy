def is_complete(self):
        # Check if the pattern is completely filled
        for row in self.grid:
            if any(cell == 0 for cell in row):
                return False
        return True