def set_reminder(self, task, reminder_time):
        self.notifications[task] = reminder_time
        print(f"Reminder set for task '{task}' at '{reminder_time}'.")