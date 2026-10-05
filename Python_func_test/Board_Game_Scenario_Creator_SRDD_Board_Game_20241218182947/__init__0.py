def __init__(self, dimensions=(10, 10)):
        self.dimensions = dimensions
        self.layout = [[None for _ in range(dimensions[1])] for _ in range(dimensions[0])]