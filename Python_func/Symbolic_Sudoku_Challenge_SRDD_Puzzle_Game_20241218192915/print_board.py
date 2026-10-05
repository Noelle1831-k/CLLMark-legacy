def print_board(self):
        '''
        Print the current state of the board in a readable format.
        '''
        for row in self.grid:
            print(' '.join(symbol if symbol else '.' for symbol in row))