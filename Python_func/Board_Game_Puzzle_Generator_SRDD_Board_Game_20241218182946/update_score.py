def update_score(self, difficulty, elapsed_time):
        '''
        Update the score based on difficulty and elapsed time.
        '''
        base_score = {'easy': 10, 'medium': 20, 'hard': 30}
        time_penalty = elapsed_time // 10
        self.score += max(base_score[difficulty] - time_penalty, 0)