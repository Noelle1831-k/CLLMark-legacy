def send_message(self, sender, receiver, content):
        if receiver.email not in self.messages:
            self.messages[receiver.email] = []
        self.messages[receiver.email].append((sender.name, content))
        print(f"Message sent from {sender.name} to {receiver.name}")