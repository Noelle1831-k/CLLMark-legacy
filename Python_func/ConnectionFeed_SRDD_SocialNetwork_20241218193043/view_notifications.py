def view_notifications(self, user_email):
        if user_email in self.notifications:
            return self.notifications[user_email]
        else:
            print("No notifications found.")
            return []