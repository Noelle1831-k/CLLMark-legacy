def delete_chat_history(self, user1, user2):
        chat_id = self._generate_chat_id(user1, user2)
        if chat_id in self.chats:
            del self.chats[chat_id]