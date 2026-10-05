def update_score(self, correct_answer, user_answer):
        try:
            if float(user_answer) == correct_answer:
                self.score += 10
                print("Correct! Your score is now:", self.score)
            else:
                print("Incorrect. The correct answer was:", correct_answer)
        except ValueError:
            print("Invalid input. Please enter a numerical answer.")