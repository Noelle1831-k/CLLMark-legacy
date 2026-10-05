def get_exercise(self):
        '''
        Retrieves a specific exercise.
        '''
        if self.exercises:
            return self.exercises.pop(0)
        return None