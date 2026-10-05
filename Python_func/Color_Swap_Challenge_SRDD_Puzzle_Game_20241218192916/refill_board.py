def refill_board(self):
        for x in range(8):
            for y in range(8):
                if self.board[x][y] is None:
                    self.board[x][y] = random.choice(self.colors)