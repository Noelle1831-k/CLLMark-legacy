def set_reminder(self, task, reminder_time):
        '''
        Set a reminder for a task.
        '''
        self.reminders[task.name] = reminder_time