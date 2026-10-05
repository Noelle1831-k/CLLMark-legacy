def set_reminder(self, task_name, reminder_time):
        self.reminders[task_name] = reminder_time
        print(f"Reminder set for task '{task_name}' at {reminder_time}.")