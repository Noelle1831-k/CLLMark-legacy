def print_block(shape):
        """
        Prints the block's shape in a readable format.
        """
        for row in shape:
            print(" ".join(str(cell) for cell in row))