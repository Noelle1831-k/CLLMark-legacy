def rotate_shape(self, shape):
        # Rotate the shape matrix
        return [list(reversed(col)) for col in zip(*shape)]