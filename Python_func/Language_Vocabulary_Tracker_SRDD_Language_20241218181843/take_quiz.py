def take_quiz(self):
        '''
        Start a quiz with the current words in the vocabulary.
        '''
        questions = list(self.words.items())
        self.quiz = Quiz(questions)
        self.quiz.start()