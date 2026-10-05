def send_reminder(self, user):
        for task in user.tasks:
            print(f"Reminder: Task '{task.description}' is due soon!")