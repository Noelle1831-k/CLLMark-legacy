def is_correct_position(self):
        '''
        Check if the piece is in the correct position and orientation.
        '''
        return self.current_position == self.correct_position and self.orientation == 0