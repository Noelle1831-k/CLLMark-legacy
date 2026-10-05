def send_reminder(self, user_profile, message):
        self.notifications.append((user_profile, message))
        print(f"Reminder for {user_profile.name}: {message}")