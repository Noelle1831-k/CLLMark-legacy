def receive_message(self, message):
        self.messages.append((self.user2.name, message))
        print(f"{self.user2.name} to {self.user1.name}: {message}")