def set_reminder(self, task_name, reminder_time):
        reminder = {
            'task_name': task_name,
            'reminder_time': reminder_time
        }
        self.reminders.append(reminder)