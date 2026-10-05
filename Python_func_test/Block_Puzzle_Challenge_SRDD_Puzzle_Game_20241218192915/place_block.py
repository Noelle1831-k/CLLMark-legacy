def place_block(self, block, position):
        """
        Attempts to place a block on the grid at the specified position.
        """
        shape = block.get_shape()
        rows, cols = len(shape), len(shape[0])
        x, y = position
        # Validate if block can be placed
        for i in range(rows):
            for j in range(cols):
                if shape[i][j] == 1:
                    if (x + i >= self.rows or y + j >= self.cols or
                            self.grid[x + i][y + j] == 1):
                        print("Block cannot be placed.")
                        return False
        # Place the block
        for i in range(rows):
            for j in range(cols):
                if shape[i][j] == 1:
                    self.grid[x + i][y + j] = 1
        print("Block placed successfully.")
        return True