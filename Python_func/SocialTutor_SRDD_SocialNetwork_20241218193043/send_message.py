def send_message(self, sender, receiver, content):
        # Validate sender and receiver
        if sender not in self.users or receiver not in self.users:
            raise ValueError("Sender or receiver not found.")
        message = Message(sender, receiver, content)
        self.messages.append(message)
        self.database.add_message(message)
        return message