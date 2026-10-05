def get_feedback(self):
        '''
        Returns feedback based on difficulty.
        '''
        if self.difficulty > 5:
            return f"Great job on the challenging {self.name}!"
        return f"Nice work on the {self.name}!"