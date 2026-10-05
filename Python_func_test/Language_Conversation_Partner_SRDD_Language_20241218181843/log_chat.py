def log_chat(self, message):
        self.chat_log.append(message)
        self.user.add_chat_history(message)
        self.partner.add_chat_history(message)