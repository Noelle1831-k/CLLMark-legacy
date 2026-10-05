def add_reminder(self, task, reminder_time=None):
        '''
        Adds a reminder for the given task.
        '''
        if reminder_time is None:
            reminder_time = task.deadline - datetime.timedelta(days=1)
        self.reminders.append((task, reminder_time))