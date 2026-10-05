def start_challenge(self):
        self.user.set_language(input("Select your target language: "))
        self.user.set_difficulty(input("Select difficulty level: "))
        self.current_challenge = challenge.Challenge(self.user.language, self.user.difficulty)
        self.current_challenge.load_recordings()
        self.get_user_input()