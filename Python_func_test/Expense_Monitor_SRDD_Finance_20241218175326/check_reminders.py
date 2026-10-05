def check_reminders(self):
        today = datetime.date.today().strftime("%Y-%m-%d")
        for reminder in self.reminders:
            if reminder[0] == today:
                print(f"Reminder: {reminder[1]}")