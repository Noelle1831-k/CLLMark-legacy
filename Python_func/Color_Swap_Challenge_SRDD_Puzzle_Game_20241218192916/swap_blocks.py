def swap_blocks(self, move):
        x1, y1, x2, y2 = move
        self.board[x1][y1], self.board[x2][y2] = self.board[x2][y2], self.board[x1][y1]