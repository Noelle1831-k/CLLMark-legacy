def display(self):
        '''
        Display the current arrangement of the puzzle.
        '''
        print("Current Puzzle Arrangement:")
        for piece in self.arrangement:
            piece.display()