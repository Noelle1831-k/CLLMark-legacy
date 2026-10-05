def get_empty_positions(self):
        '''
        Get a list of all empty positions on the board.
        '''
        empty_positions = []
        for r in range(9):
            for c in range(9):
                if self.grid[r][c] is None:
                    empty_positions.append((r, c))
        return empty_positions