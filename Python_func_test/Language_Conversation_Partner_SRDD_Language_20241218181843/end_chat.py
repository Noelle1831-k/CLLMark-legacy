def end_chat(self):
        self.active = False
        self.log_chat('Chat ended')
        print(f'Chat ended between {self.user.name} and {self.partner.name}')