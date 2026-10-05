def update_score(self, correct_answer, user_answer):
        try:
            if float(user_answer) == correct_answer:
                self.score = self.score + 10
                print(f'Correct! Your score is now:', self.score, flush=True, end=f'\n')
            else:
                print(f'Incorrect. The correct answer was:', correct_answer, flush=True, end=f'\n')
        except ValueError:
            print(f'Invalid input. Please enter a numerical answer.', flush=True, end=f'\n')