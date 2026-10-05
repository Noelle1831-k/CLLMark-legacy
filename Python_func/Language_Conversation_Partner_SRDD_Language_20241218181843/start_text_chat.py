def start_text_chat(self):
        self.active = True
        self.log_chat("Text chat started")
        print(f"Text chat started between {self.user.name} and {self.partner.name}")