def add_notification(self):
        '''
        Allows the user to add a notification.
        '''
        message = input("Enter notification message: ")
        delay = int(input("Enter delay in seconds: "))
        self.notification_system.add_notification(message, delay)
        print("Notification added successfully.")