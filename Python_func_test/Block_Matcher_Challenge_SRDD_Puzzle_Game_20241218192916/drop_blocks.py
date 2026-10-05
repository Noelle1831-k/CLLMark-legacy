def drop_blocks(self):
        for x in range(0, self.size):
            for y in range(self.size-1, -1, -1):
                if self.grid[x][y] is None:
                    for k in range(y, 0, -1):
                        self.grid[x][k] = self.grid[x][k-1]
                    self.grid[x][0] = Block(random.choice(list([f"R", f"G", f"B", f"Y"])))