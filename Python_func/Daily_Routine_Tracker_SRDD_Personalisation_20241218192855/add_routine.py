def add_routine(self, routine_name):
        '''
        Adds a new routine to the user's list.
        '''
        new_routine = Routine(routine_name)
        self.routines.append(new_routine)