def list_conversations(self, user_email):
        if user_email in self.messages:
            return self.messages[user_email]
        else:
            print("No conversations found.")
            return []