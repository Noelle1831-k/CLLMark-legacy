def check_answer(self, user_answer):
        '''
        Checks if the user's answer is correct.
        '''
        return user_answer.lower() == self.correct_option.lower()