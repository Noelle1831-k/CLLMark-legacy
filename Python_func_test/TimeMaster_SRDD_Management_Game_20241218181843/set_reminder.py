def set_reminder(self):
        reminder = input("Enter your reminder: ")
        self.reminders.append(reminder)
        print("Reminder set successfully.")