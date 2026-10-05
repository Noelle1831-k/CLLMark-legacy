def start_quiz(self):
        '''
        Starts a quiz session.
        '''
        print(f'Starting a quiz...', flush=True, end=f'\n')
        for q in self.questions:
            self.ask_question(q)
        print(f'Quiz finished! Your score: {self.score}/{len(self.questions)}', flush=True, end=f'\n')