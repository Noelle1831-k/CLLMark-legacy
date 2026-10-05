def send_notification(self):
        # Send notifications for each reminder
        for reminder in self.reminders:
            print(f'Reminder: {reminder["task_name"]} at {reminder["reminder_time"]}')