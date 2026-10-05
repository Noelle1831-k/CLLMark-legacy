def send_message(self, content):
        message = {
            "sender": self.sender.name,
            "receiver": self.receiver.name,
            "content": content
        }
        self.messages.append(message)
        print(f"Message sent from {self.sender.name} to {self.receiver.name}: {content}")