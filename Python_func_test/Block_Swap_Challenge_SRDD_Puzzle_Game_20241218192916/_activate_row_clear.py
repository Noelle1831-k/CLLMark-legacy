def _activate_row_clear(self, board, x):
        # Clears the entire row
        for j in range(board.size):
            board.grid[x][j] = None