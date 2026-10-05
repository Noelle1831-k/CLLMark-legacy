def display_notifications(self):
        for notification in self.notifications:
            print(f"Notification for {notification[0].name}: {notification[1]}")