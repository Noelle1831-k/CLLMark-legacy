def set_reminder(self, task_id, reminder_time):
        self.reminders[task_id] = reminder_time
        print(f"Reminder set for task ID {task_id} at {reminder_time}.")