def notify_user(self):
        for achievement, date in self.reminders.items():
            print(f"Reminder: {achievement} is due on {date}")