def evaluate_exercise(self, responses):
        score = 0
        for exercise, response in zip(self.exercises, responses):
            if response:
                score += 1
        self.user.update_progress('exercise', score)
        return score