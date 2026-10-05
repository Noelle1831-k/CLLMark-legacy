def update_reminder(self, new_message=None, new_time=None):
        '''
        Update the reminder's message or time.
        '''
        if new_message:
            self.message = new_message
        if new_time:
            self.reminder_time = datetime.datetime.strptime(new_time, "%Y-%m-%d %I:%M %p")
        self.is_set = False
        print("Reminder updated. Please set it again.")