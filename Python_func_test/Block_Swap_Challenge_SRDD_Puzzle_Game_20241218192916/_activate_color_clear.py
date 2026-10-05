def _activate_color_clear(self, board, x, y):
        # Clears all blocks of the same color as the specified block
        target_color = board.grid[x][y].color
        for i in range(0, board.size):
            for j in range(0, board.size):
                if board.grid[i][j] and not (board.grid[i][j].color != target_color):
                    board.grid[i][j] = None