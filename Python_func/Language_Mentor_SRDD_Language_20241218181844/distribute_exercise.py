def distribute_exercise(self, user):
        '''
        Distributes exercises to users.
        '''
        exercise = self.create_exercise()
        user.update_progress(exercise)