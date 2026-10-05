def reset_score(self):
        '''
        Resets the score and score history for a new game session.
        '''
        self.score = 0
        self.score_history.clear()
        self.reset_combo()