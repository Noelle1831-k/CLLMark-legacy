def trigger_reminder(self):
        '''
        Trigger the reminder, notifying the user.
        '''
        print(f"Reminder: {self.message} at {self.reminder_time.strftime('%Y-%m-%d %I:%M %p')}")
        self.is_set = False