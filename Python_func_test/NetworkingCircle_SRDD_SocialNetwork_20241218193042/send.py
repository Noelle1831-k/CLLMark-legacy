def send(self):
        print(f"Sending message from {self.sender.name} to {self.receiver.name}: {self.content}")
        self.network.messages.append(self)