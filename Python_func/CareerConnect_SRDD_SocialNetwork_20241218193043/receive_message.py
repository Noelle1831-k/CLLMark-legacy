def receive_message(self):
        for sender, message in self.messages:
            print(f"Message from {sender}: {message}")