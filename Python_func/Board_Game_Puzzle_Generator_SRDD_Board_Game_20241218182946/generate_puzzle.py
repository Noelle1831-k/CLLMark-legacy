def generate_puzzle(self):
        '''
        Generate a random puzzle from the available categories.
        '''
        puzzle_types = [LogicPuzzle, PatternRecognitionPuzzle, SpatialPuzzle]
        self.current_puzzle = random.choice(puzzle_types)()
        self.current_puzzle.generate()