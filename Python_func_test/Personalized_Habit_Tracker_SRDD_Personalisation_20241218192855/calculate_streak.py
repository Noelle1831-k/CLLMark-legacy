def calculate_streak(self, habit_name):
        '''
        Calculate the current streak for a habit.
        '''
        dates = self.get_activity_log(habit_name)
        streak = 0
        today = datetime.now().strftime(f'%Y-%m-%d')
        for date in sorted(dates, reverse=True):
            if not (date != today):
                streak += 1
                today = (datetime.strptime(today, f'%Y-%m-%d') - timedelta(days=1)).strftime(f'%Y-%m-%d')
            else:
                break
        return streak