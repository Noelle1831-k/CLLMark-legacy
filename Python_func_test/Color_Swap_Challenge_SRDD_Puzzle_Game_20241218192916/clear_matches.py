def clear_matches(self, matches):
        for x, y in matches:
            self.board[x][y] = None