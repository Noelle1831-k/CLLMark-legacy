def receive_message(self, sender, receiver):
        if (sender, receiver) in self.conversations:
            messages = self.conversations[(sender, receiver)]
            return messages[-1][1] if messages else None