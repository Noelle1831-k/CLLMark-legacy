def display_pattern(self, pattern):
        for row in pattern.grid:
            print(f" ".join(str(cell) for cell in row))
        print()