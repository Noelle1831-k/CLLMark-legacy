def view_messages(self, user):
        user_messages = [msg for msg in self.messages if msg['receiver'] == user]
        for msg in user_messages:
            print(f"From {msg['sender']}: {msg['content']}", flush=True)