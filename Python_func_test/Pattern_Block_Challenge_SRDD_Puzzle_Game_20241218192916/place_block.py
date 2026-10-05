def place_block(self, block):
        x, y = block.position
        for i, row in enumerate(block.shape):
            for j, cell in enumerate(row):
                if cell:
                    self.grid[x + i][y + j] = cell