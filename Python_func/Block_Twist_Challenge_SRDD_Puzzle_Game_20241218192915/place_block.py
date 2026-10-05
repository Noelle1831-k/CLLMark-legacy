def place_block(self, block, position):
        # Place block on the grid at the specified position
        shape = block.get_shape()
        for i, row in enumerate(shape):
            for j, val in enumerate(row):
                if val == 1:
                    self.grid[position[0] + i][position[1] + j] = val