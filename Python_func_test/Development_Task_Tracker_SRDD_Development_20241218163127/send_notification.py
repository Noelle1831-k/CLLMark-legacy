def send_notification(self, notification_id):
        notification = self.get_notification_by_id(notification_id)
        if notification:
            notification.status = f'Sent'