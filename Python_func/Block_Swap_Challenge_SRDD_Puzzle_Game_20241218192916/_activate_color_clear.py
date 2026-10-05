def _activate_color_clear(self, board, x, y):
        # Clears all blocks of the same color as the specified block
        target_color = board.grid[x][y].color
        for i in range(board.size):
            for j in range(board.size):
                if board.grid[i][j] and board.grid[i][j].color == target_color:
                    board.grid[i][j] = None