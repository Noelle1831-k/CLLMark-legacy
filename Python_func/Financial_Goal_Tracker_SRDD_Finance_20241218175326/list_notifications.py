def list_notifications(self):
        '''
        Lists all notifications sent by the NotificationManager.
        '''
        if not self.notifications:
            print("No notifications yet.")
        else:
            for notification in self.notifications:
                print(notification)