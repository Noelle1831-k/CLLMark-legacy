def evaluate(self, answers):
        '''
        Evaluate the user's answers and calculate the score.
        The method compares the user's answers with the correct definitions.
        '''
        for word, user_answer in answers:
            correct_answer = next(definition for w, definition in self.questions if w == word)
            if user_answer.strip().lower() == correct_answer.lower():
                self.score += 1
            else:
                print(f'Incorrect. The correct definition of "{word}" is: {correct_answer}')
        print(f'Your score: {self.score}/{len(self.questions)}')
        self.display_feedback()