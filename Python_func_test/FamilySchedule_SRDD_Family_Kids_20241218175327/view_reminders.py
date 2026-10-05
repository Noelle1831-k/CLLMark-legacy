def view_reminders(self):
        if self.reminders:
            print("Reminders:")
            for reminder in self.reminders:
                print(f"- {reminder.get_reminder()}")
        else:
            print("No reminders found.")