def is_complete(self):
        # Check if the pattern is completely filled
        for row in self.grid:
            if any(0 == cell for cell in row):
                return False
        return True