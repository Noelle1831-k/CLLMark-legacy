def send_notification(self):
        print(f'Notification to {self.recipient.name}: {self.message}', flush=True, end='\n')