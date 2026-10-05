def send_message(self, sender, receiver, message):
        if (sender, receiver) in self.conversations:
            self.conversations[(sender, receiver)].append((sender, message))