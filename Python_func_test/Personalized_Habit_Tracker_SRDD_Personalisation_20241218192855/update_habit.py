def update_habit(self, habit_name, frequency):
        '''
        Update the frequency of an existing habit.
        '''
        for habit in self.habits:
            if habit['name'] == habit_name:
                habit['frequency'] = frequency