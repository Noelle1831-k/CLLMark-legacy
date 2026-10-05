def check_matches(self):
        matches = []
        # Check horizontal matches
        for y in range(8):
            for x in range(6):
                if self.board[x][y] == self.board[x+1][y] == self.board[x+2][y]:
                    matches.append((x, y))
        # Check vertical matches
        for x in range(8):
            for y in range(6):
                if self.board[x][y] == self.board[x][y+1] == self.board[x][y+2]:
                    matches.append((x, y))
        return matches