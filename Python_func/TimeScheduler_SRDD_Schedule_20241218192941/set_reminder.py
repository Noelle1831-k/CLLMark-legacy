def set_reminder(self, task_name, reminder_time):
        self.reminders[task_name] = reminder_time
        print(f"Reminder for '{task_name}' set at {reminder_time}.")