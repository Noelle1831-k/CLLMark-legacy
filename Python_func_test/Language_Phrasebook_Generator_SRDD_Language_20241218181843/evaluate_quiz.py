def evaluate_quiz(self, answers):
        score = 0
        for question, answer in zip(self.questions, answers):
            if question['answer'] == answer:
                score += 1
        self.user.update_progress('quiz', score)
        return score