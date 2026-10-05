def send_message(self, message):
        self.messages.append((self.sender.name, message))
        print(f"Message sent from {self.sender.name} to {self.receiver.name}: {message}")