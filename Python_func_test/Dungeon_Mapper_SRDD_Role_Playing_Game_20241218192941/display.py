def display(self):
        for row in self.grid:
            print(' '.join([tile.type for tile in row]))