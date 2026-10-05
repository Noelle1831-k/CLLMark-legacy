def view_reminders(self):
        if not self.reminders:
            print("No reminders available.")
        else:
            print("Your reminders:")
            for i, reminder in enumerate(self.reminders, 1):
                print(f"{i}. {reminder}")