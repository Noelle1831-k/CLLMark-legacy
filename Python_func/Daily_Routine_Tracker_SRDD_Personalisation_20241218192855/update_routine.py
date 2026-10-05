def update_routine(self, routine_name):
        '''
        Updates an existing routine.
        '''
        for routine in self.routines:
            if routine.name == routine_name:
                routine.track_progress()
                routine.set_reminder()