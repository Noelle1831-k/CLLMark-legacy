def place_symbol(self, move):
        '''
        Place a symbol on the board at the specified position.
        '''
        row, col, symbol = move
        if self.is_valid_move(move):
            self.grid[row][col] = symbol
        else:
            raise ValueError("Invalid move attempted.")