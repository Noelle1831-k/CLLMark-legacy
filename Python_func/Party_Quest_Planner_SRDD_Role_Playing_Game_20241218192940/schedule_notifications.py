def schedule_notifications(self):
        '''
        Schedule notifications for upcoming quests.
        '''
        recipient = input("Enter recipient name: ")
        message = input("Enter notification message: ")
        self.notifications.append({'recipient': recipient, 'message': message})
        print(f"Notification scheduled for {recipient}.")
        self.send_notification(message, recipient)