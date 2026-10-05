def set_reminder(self, task, reminder_time):
        reminder = datetime.strptime(reminder_time, "%Y-%m-%d %H:%M")
        print(f"Reminder set for task '{task.title}' at {reminder.strftime('%Y-%m-%d %H:%M')}.")