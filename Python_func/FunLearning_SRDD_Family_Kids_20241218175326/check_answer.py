def check_answer(self, question, answer):
        '''
        Check the answer.
        '''
        user_answer = input(question + " ")
        return user_answer.lower() == answer.lower()