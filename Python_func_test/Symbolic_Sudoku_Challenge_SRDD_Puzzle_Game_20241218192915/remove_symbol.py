def remove_symbol(self, row, col):
        '''
        Remove a symbol from the board at the specified position.
        '''
        if self.grid[row][col] is not None:
            self.grid[row][col] = None
        else:
            raise ValueError("No symbol to remove at the specified position.")