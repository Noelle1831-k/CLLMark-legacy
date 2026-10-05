def select_quiz(self, subject, difficulty):
        '''
        Selects a quiz based on subject and difficulty.
        '''
        for quiz in self.quizzes:
            if quiz.subject == subject and quiz.difficulty == difficulty:
                return quiz
        return None