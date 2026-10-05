def load_level(self):
        # Clear the grid and place blocks
        self.grid.clear()
        for block in self.blocks:
            self.grid.place_block(block)