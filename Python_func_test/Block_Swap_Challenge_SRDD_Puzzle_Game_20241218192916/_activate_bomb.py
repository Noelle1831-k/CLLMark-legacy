def _activate_bomb(self, board, x, y):
        # Clears a 3x3 area around the specified block
        for i in range(max(0, x-1), min(board.size, x+2)):
            for j in range(max(0, y-1), min(board.size, y+2)):
                board.grid[i][j] = None