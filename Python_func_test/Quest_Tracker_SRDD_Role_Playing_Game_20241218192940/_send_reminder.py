def _send_reminder(self, reminder):
        message = f'Reminder: Quest "{reminder["quest"].name}" is due!'
        self.notification_system.send_notification(message)