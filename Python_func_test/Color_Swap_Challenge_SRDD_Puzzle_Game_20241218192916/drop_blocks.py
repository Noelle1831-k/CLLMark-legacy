def drop_blocks(self):
        for x in range(8):
            for y in range(7, -1, -1):
                if self.board[x][y] is None:
                    for k in range(y, 0, -1):
                        self.board[x][k] = self.board[x][k-1]
                    self.board[x][0] = random.choice(self.colors)