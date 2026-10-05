def initialize_board(self, symbols, difficulty):
        '''
        Initialize the board with symbols based on the difficulty level.
        '''
        self.grid = generate_random_board(symbols.get_symbols(), difficulty)
        if not validate_board(self.grid):
            raise ValueError("Generated board is invalid.")