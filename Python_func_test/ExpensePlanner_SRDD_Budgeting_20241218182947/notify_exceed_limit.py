def notify_exceed_limit(self):
        notification_obj = notification.Notification("Budget limit exceeded", self.email)
        notification_obj.send_notification()
        self.notifications.append(notification_obj)