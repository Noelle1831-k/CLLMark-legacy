def update_progress(self, exercise):
        '''
        Updates user progress based on exercise results.
        '''
        result = exercise.generate_exercise()
        self.progress.append(result)
        self._update_level(result)