def has_possible_moves(self):
        for x in range(self.size):
            for y in range(self.size):
                if self.can_swap(x, y, x+1, y) or self.can_swap(x, y, x, y+1):
                    return True
        return False