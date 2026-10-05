def notify(self, task_name):
        if task_name in self.reminders:
            print(f"Reminder: {task_name} is scheduled at {self.reminders[task_name]}")