def rotate(self):
        """
        Rotates the block 90 degrees clockwise.
        """
        self.shape = [list(row) for row in zip(*self.shape[::-1])]