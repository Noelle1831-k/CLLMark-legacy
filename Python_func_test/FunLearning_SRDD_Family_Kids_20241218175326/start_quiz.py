def start_quiz(self):
        '''
        Start the quiz.
        '''
        print('Starting the quiz...')
        score = 0
        for question, answer in self.questions:
            user_answer = input(question + ' ')
            if user_answer.lower() == answer.lower():
                score += 1
                print('Correct!')
            else:
                print('Incorrect.')
        print(f'Quiz ended. Your score: {score}/{len(self.questions)}')