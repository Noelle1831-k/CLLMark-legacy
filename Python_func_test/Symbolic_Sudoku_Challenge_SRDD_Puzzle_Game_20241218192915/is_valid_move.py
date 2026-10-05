def is_valid_move(self, move):
        '''
        Validate a move by checking if placing the symbol at the specified
        position adheres to Sudoku rules.
        '''
        row, col, symbol = move
        if self.grid[row][col] is not None:
            return False
        if symbol in self.grid[row]:
            return False
        if symbol in [self.grid[r][col] for r in range(9)]:
            return False
        start_row, start_col = 3 * (row // 3), 3 * (col // 3)
        for r in range(start_row, start_row + 3):
            for c in range(start_col, start_col + 3):
                if self.grid[r][c] == symbol:
                    return False
        return True