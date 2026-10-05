def send_message(self, message):
        self.messages.append((self.user1.name, message))
        print(f"{self.user1.name} to {self.user2.name}: {message}")