def run(self):
        print("Welcome to WordQuizzer!")
        username = input("Enter your username: ")
        self.user = User(username)
        self.select_language()
        self.select_difficulty()
        self.select_quiz_type()
        self.start_quiz()