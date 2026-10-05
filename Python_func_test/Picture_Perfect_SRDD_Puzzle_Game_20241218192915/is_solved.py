def is_solved(self):
        '''
        Check if the puzzle is solved.
        '''
        solved = all(piece.is_correct_position() for piece in self.arrangement)
        if solved:
            print(f'Puzzle solved in {self.moves_made} moves!', flush=True, end='\n')
        return solved