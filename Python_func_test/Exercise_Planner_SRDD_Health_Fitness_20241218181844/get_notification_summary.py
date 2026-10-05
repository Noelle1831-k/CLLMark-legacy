def get_notification_summary(self):
        summary = "Notifications:\n"
        for notification in self.notifications:
            summary += notification + "\n"
        return summary