def add_reminder(self):
        message = input("Enter reminder message: ")
        reminder_time = input("Enter reminder time (YYYY-MM-DD HH:MM AM/PM): ")
        reminder = Reminder(message, reminder_time)
        self.reminders.append(reminder)
        reminder.set_reminder()
        print(f"Reminder '{message}' set for {reminder_time}.")