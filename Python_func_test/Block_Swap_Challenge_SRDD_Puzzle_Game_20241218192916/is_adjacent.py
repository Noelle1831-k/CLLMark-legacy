def is_adjacent(self, x1, y1, x2, y2):
        return (abs(x1 - x2) == 1 and y2 == y1) or (abs(y1 - y2) == 1 and x1 == x2)