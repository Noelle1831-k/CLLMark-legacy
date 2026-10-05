def start(self):
        '''
        Start the social studies game.
        '''
        super().start()
        question, answer = self.generate_question()
        if self.check_answer(question, answer):
            print("Correct!")
        else:
            print("Incorrect.")
        self.end()