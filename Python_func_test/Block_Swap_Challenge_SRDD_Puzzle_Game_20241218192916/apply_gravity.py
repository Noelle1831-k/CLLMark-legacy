def apply_gravity(self):
        for x in range(self.size):
            empty_slots = [y for y in range(self.size) if self.grid[x][y] is None]
            for y in reversed(range(self.size)):
                if self.grid[x][y] is not None and empty_slots and y < max(empty_slots):
                    self.grid[x][empty_slots.pop(0)] = self.grid[x][y]
                    self.grid[x][y] = None
            # Fill empty slots with new blocks
            for y in empty_slots:
                self.grid[x][y] = Block()