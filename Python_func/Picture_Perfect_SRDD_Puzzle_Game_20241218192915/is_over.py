def is_over(self):
        '''
        Check if the game is over.
        '''
        return self.current_level_index >= len(self.levels)