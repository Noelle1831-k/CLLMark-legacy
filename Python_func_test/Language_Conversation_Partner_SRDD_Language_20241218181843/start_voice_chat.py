def start_voice_chat(self):
        self.active = True
        self.log_chat("Voice chat started")
        print(f"Voice chat started between {self.user.name} and {self.partner.name}")