def get_chat_history(self, user1, user2):
        chat_id = self._generate_chat_id(user1, user2)
        return self.chats.get(chat_id, [])