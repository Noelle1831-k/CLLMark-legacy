def send_reminder(self, message):
        self.notifications.append(f"Reminder for {self.user.name}: {message}")