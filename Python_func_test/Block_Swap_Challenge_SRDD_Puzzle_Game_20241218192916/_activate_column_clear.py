def _activate_column_clear(self, board, y):
        # Clears the entire column
        for i in range(board.size):
            board.grid[i][y] = None