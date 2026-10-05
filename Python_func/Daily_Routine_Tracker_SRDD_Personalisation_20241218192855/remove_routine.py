def remove_routine(self, routine_name):
        '''
        Removes a routine from the user's list.
        '''
        self.routines = [r for r in self.routines if r.name != routine_name]