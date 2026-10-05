def start_quiz(self):
        '''
        Starts a quiz session.
        '''
        print("Starting a quiz...")
        for q in self.questions:
            self.ask_question(q)
        print(f"Quiz finished! Your score: {self.score}/{len(self.questions)}")