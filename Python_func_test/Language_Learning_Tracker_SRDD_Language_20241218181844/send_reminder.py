def send_reminder(self):
        current_time = datetime.datetime.now()
        missed_reminders = []
        for reminder in self.reminders:
            message, reminder_time = reminder
            reminder_time_obj = datetime.datetime.strptime(reminder_time, "%Y-%m-%d %H:%M")
            # Allow for a 1-minute tolerance window
            if 0 <= (current_time - reminder_time_obj).total_seconds() <= 60:
                print(f"Reminder: {message}")
            elif (current_time - reminder_time_obj).total_seconds() > 60:
                missed_reminders.append((message, reminder_time))
        if missed_reminders:
            print("Missed Reminders:")
            for missed in missed_reminders:
                print(f"{missed[0]} scheduled for {missed[1]}")