def rotate(self):
        '''
        Rotate the puzzle piece.
        '''
        self.orientation = (self.orientation + 90) % 360  # Assuming 90-degree rotations