def validate_move(self, move, board):
        x1, y1, x2, y2 = move
        if 0 <= x1 < 8 and 0 <= y1 < 8 and 0 <= x2 < 8 and 0 <= y2 < 8:
            if abs(x1 - x2) + abs(y1 - y2) == 1:
                return True
        return False