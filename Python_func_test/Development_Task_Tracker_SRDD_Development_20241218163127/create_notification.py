def create_notification(self, message, recipient):
        notification_id = generate_id()
        notification = Notification(notification_id, message, recipient)
        self.notifications[notification_id] = notification
        return notification_id