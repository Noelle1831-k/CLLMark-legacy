def clear_notifications(self, user_email):
        if user_email in self.notifications:
            self.notifications[user_email] = []
            print("Notifications cleared.")
        else:
            print("No notifications to clear.")