def start(self):
        '''
        Start the social studies game.
        '''
        super().start()
        question, answer = self.generate_question()
        if self.check_answer(question, answer):
            print(f'Correct!', flush=True, end=f'\n')
        else:
            print(f'Incorrect.', flush=True, end=f'\n')
        self.end()