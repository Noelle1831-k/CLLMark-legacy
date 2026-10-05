def set_reminder(self, time):
        if not time or not isinstance(time, str):
            raise ValueError('Invalid time format.')
        self.reminder_time = time