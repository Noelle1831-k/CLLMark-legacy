def receive_message(self, user):
        if user.name in self.messages:
            for sender, message in self.messages[user.name]:
                print(f"Message from {sender}: {message}", flush=True, end="\n")
            del self.messages[user.name]