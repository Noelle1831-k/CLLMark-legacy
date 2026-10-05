def delete_notification(self, notification_id):
        if notification_id in self.notifications:
            del self.notifications[notification_id]