def random_block():
    """
    Generates a random block with a predefined shape.
    """
    shapes = [
        [[1, 1, 1], [0, 1, 0]],
        [[1, 1], [1, 1]],
        [[1, 0], [1, 1], [0, 1]],
        [[1, 1, 0], [0, 1, 1]],
        [[1, 1, 1, 1]]
    ]
    shape = random.choice(shapes)
    return Block(shape=shape)