def set_reminder(self, message, reminder_time):
        reminder = Reminder(message, reminder_time)
        reminder.set()