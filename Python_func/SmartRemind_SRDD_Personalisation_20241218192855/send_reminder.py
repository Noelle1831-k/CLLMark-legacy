def send_reminder(self, task):
        print(f"Reminder: Task '{task['name']}' is due on {task['due_date'].strftime('%Y-%m-%d')} with priority {task['priority']}.")