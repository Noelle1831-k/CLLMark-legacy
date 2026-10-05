def initiate_chat(self, user1, user2, message):
        chat_id = self._generate_chat_id(user1, user2)
        if chat_id not in self.chats:
            self.chats[chat_id] = []
        self.chats[chat_id].append((user1.name, message))