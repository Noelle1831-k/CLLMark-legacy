def check_answer(self, user_answer):
        return user_answer.strip().lower() == self.answer.lower()