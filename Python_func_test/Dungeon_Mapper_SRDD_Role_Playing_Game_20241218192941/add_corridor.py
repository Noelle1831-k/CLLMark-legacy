def add_corridor(self, path):
        for x, y in path:
            self.grid[x][y] = Tile('corridor')