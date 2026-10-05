def render_grid(self, grid):
        for row in grid.grid:
            print(" ".join(["#" if cell else "." for cell in row]))