def send_reminder(self, task_name):
        if task_name in self.reminders:
            print(f"Reminder: Time to work on '{task_name}'!")
        else:
            print(f"No reminder set for '{task_name}'.")