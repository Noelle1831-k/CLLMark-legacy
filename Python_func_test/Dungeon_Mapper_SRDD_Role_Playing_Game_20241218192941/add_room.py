def add_room(self, x, y, width, height):
        for i in range(x, x + width):
            for j in range(y, y + height):
                self.grid[i][j] = Tile('room')