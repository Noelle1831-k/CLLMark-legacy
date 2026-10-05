def log_activity(self, habit_name, date=None):
        '''
        Log an activity for a habit on a specific date.
        '''
        date = date or datetime.now().strftime('%Y-%m-%d')
        if habit_name not in self.activity_log:
            self.activity_log[habit_name] = []
        self.activity_log[habit_name].append(date)