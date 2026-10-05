def get_reminder(self):
        '''
        Get the details of the reminder.
        '''
        return f"Reminder: {self.message}, Time: {self.reminder_time.strftime('%Y-%m-%d %I:%M %p')}"