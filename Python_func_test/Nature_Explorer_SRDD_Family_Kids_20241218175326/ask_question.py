def ask_question(self, question):
        '''
        Asks a question to the user.
        '''
        user_answer = input(question["question"] + " ")
        self.check_answer(user_answer, question["answer"])