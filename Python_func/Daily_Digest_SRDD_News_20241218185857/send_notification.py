def send_notification(self, digest):
        print("Sending notification...")
        print(digest)
        self.send_email(digest)