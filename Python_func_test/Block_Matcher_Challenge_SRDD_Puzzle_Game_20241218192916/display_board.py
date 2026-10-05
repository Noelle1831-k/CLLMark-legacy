def display_board(self):
        for row in self.grid:
            print(' '.join(block.get_color() for block in row))