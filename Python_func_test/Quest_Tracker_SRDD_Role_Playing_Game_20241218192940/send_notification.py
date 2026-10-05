def send_notification(self, message):
        self.notifications.append(message)
        print(f'Notification: {message}', flush=True, end='\n')