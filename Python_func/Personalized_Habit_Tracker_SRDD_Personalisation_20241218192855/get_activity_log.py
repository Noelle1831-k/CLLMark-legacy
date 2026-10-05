def get_activity_log(self, habit_name):
        '''
        Get the activity log for a specific habit.
        '''
        return self.activity_log.get(habit_name, [])