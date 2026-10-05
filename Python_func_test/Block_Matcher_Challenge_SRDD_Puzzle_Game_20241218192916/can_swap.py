def can_swap(self, x1, y1, x2, y2):
        if x2 < self.size and y2 < self.size:
            self.swap_blocks(x1, y1, x2, y2)
            if self.find_matches():
                self.swap_blocks(x1, y1, x2, y2)
                return True
            self.swap_blocks(x1, y1, x2, y2)
        return False