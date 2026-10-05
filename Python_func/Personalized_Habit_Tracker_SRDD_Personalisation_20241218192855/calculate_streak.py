def calculate_streak(self, habit_name):
        '''
        Calculate the current streak for a habit.
        '''
        dates = self.get_activity_log(habit_name)
        streak = 0
        today = datetime.now().strftime('%Y-%m-%d')
        for date in sorted(dates, reverse=True):
            if date == today:
                streak += 1
                today = (datetime.strptime(today, '%Y-%m-%d') - timedelta(days=1)).strftime('%Y-%m-%d')
            else:
                break
        return streak