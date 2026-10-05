def get_notifications(self):
        """
        Retrieves all scheduled notifications.
        """
        if not self.notifications:
            return ["No notifications available."]
        return self.notifications