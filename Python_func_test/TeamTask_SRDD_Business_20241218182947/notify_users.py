def notify_users(self, task):
        for user in self.users:
            if user == task.assignee:
                notification = Notification(f"Task '{task.title}' status updated to {task.status}", user)
                notification.send_notification()