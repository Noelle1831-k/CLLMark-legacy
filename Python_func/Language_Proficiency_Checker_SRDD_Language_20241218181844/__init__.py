def __init__(self):
        self.questions = load_questions()
        self.user_answers = []
        self.correct_answers = 0
        self.total_questions = len(self.questions)
        self.score = 0