def notify_updates(self, schedule):
        for user in schedule.shared_with:
            notification.Notification().send_notification(user, schedule)