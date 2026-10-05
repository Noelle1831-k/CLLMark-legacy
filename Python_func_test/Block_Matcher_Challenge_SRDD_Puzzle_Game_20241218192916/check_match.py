def check_match(self, x, y):
        color = self.grid[x][y].get_color()
        return (x > 1 and self.grid[x-1][y].get_color() == color and self.grid[x-2][y].get_color() == color) or \
               (y > 1 and self.grid[x][y-1].get_color() == color and self.grid[x][y-2].get_color() == color)