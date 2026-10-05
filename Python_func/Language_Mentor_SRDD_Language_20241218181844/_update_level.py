def _update_level(self, result):
        '''
        Updates user level based on exercise results.
        '''
        if "correct" in result:
            self.level += 1
        elif "incorrect" in result and self.level > 1:
            self.level -= 1