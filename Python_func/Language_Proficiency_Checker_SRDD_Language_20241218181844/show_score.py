def show_score(self):
        '''
        Displays the final score and feedback
        '''
        print(f"Your score is: {self.score}")
        feedback = generate_feedback(self.correct_answers, self.total_questions)
        print(feedback)
        improvement_suggestion = suggest_improvement(self.score)
        print(improvement_suggestion)