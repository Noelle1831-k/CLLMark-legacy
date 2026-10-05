def check_answer(self, user_answer, correct_answer):
        '''
        Checks the user's answer.
        '''
        if user_answer.lower() == correct_answer.lower():
            print("Correct!")
            self.score += 1
        else:
            print(f"Wrong! The correct answer is {correct_answer}.")