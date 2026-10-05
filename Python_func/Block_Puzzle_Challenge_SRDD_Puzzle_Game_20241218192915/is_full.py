def is_full(self):
        """
        Checks if the grid is full and no more blocks can be placed.
        """
        return any(all(cell == 1 for cell in row) for row in self.grid)