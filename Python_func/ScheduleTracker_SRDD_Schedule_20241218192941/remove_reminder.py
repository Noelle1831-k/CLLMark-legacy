def remove_reminder(self, task_id):
        if task_id in self.reminders:
            del self.reminders[task_id]
            print(f"Reminder for task ID {task_id} removed.")
        else:
            print("Reminder not found.")