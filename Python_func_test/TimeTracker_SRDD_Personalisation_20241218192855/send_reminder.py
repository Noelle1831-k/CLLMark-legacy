def send_reminder(self, task):
        '''
        Send a reminder to the user.
        '''
        if task.name in self.reminders:
            print(f"Reminder: {task.name} is due at {self.reminders[task.name]}")