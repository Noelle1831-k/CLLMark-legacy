def add_habit(self, habit_name, frequency):
        '''
        Add a new habit to the tracker.
        '''
        self.habits.append({'name': habit_name, 'frequency': frequency})