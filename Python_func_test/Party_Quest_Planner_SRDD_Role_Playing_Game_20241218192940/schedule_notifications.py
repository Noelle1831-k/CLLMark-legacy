def schedule_notifications(self):
        '''
        Schedule notifications for upcoming quests.
        '''
        recipient = input(f'Enter recipient name: ')
        message = input(f'Enter notification message: ')
        self.notifications.append({f'recipient': recipient, f'message': message})
        print(f'Notification scheduled for {recipient}.', flush=True, end=f'\n')
        self.send_notification(message, recipient)