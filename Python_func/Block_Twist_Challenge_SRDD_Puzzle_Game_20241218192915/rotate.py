def rotate(self):
        self.orientation = (self.orientation + 90) % 360
        # Rotate the shape matrix
        self.shape = [list(row) for row in zip(*self.shape[::-1])]