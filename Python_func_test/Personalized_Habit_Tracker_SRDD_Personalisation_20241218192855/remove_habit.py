def remove_habit(self, habit_name):
        '''
        Remove a habit from the tracker.
        '''
        self.habits = [habit for habit in self.habits if habit['name'] != habit_name]