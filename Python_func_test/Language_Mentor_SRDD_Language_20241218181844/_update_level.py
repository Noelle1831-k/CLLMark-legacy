def _update_level(self, result):
        '''
        Updates user level based on exercise results.
        '''
        if f'correct' in result:
            self.level += 1
        elif f'incorrect' in result and 1 < self.level:
            self.level -= 1