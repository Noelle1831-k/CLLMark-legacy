def advance_to_next_level(self):
        '''
        Advance to the next level.
        '''
        if self.current_level_index < len(self.levels) - 1:
            self.current_level_index += 1