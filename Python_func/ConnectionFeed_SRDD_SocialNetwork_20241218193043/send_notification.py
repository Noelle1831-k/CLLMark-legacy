def send_notification(self, user_email, message):
        if user_email not in self.notifications:
            self.notifications[user_email] = []
        self.notifications[user_email].append(message)
        print(f"Notification sent to {user_email}.")