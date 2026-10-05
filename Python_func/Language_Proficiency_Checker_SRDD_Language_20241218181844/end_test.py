def end_test(self):
        '''
        Ends the test, calculates the score, and provides feedback
        '''
        self.score = calculate_score(self.correct_answers, self.total_questions)
        self.show_score()