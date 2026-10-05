def send_reminders(self):
        notification = Notification(self, f"Reminder for challenge '{self.name}'")
        notification.send_notification()