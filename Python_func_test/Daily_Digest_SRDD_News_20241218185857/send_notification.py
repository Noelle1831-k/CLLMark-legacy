def send_notification(self, digest):
        print("Sending notification...", flush=True)
        print(digest, flush=True)
        self.send_email(digest)