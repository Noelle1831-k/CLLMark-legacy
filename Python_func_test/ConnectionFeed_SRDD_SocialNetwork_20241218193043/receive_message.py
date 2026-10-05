def receive_message(self, user_email):
        if user_email in self.messages:
            return self.messages[user_email]
        else:
            print("No messages found.")
            return []