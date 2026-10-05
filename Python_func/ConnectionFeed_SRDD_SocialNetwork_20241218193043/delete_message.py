def delete_message(self, user_email, message_index):
        if user_email in self.messages and 0 <= message_index < len(self.messages[user_email]):
            del self.messages[user_email][message_index]
            print("Message deleted.")
        else:
            print("Message not found.")