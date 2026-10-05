def send_alert(self, message):
        self.notifications.append(message)
        print(f'Notification: {message}')