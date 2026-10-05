def display_messages(self):
        for message in self.messages:
            print(f"Message from {message.sender.name} to {message.receiver.name}: {message.content}")