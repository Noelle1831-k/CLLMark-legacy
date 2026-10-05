def clear_lines(self):
        """
        Clears all completed rows and columns and returns the number of lines cleared.
        """
        lines_cleared = 0
        # Check rows
        for i in range(self.rows):
            if all(self.grid[i][j] == 1 for j in range(self.cols)):
                lines_cleared += 1
                self.grid.pop(i)
                self.grid.insert(0, [0] * self.cols)
        # Check columns
        for j in range(self.cols):
            if all(self.grid[i][j] == 1 for i in range(self.rows)):
                lines_cleared += 1
                for i in range(self.rows):
                    self.grid[i][j] = 0
        print(f"Cleared {lines_cleared} line(s).")
        return lines_cleared