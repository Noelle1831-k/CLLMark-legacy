def log_score(self, drift_score):
        '''
        Logs the score of each drift for analysis and debugging purposes.
        '''
        self.score_history.append(drift_score)