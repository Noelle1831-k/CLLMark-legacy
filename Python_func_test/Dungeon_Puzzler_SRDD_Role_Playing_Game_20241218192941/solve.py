def solve(self, attempt):
        '''
        Checks if the player's attempt solves the puzzle.
        '''
        if attempt == self.solution:
            print("Correct! The puzzle is solved.")
            return True
        else:
            print("Incorrect. Try again.")
            return False