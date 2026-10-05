def rotate(self):
        # Rotate the block by 90 degrees
        self.rotation = (self.rotation + 90) % 360
        self.shape = self.rotate_shape(self.shape)