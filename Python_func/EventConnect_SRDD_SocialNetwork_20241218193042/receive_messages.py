def receive_messages(self, user):
        if user.email in self.messages:
            for sender, content in self.messages[user.email]:
                print(f"Message from {sender}: {content}")
        else:
            print(f"No messages for {user.name}")