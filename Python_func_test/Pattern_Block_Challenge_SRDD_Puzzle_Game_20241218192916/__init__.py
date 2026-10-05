def __init__(self, level_data):
        # Initialize level with grid size, blocks, and target shape
        self.grid = Grid(level_data["grid_size"])
        self.blocks = [Block(data) for data in level_data["blocks"]]
        self.target_shape = level_data["target_shape"]