def __init__(self, language, difficulty, quiz_type):
        self.language = language
        self.difficulty = difficulty
        self.quiz_type = quiz_type
        self.database = Database()
        self.words = self.database.get_words(language, difficulty)
        self.current_question = None
        self.current_answer = None