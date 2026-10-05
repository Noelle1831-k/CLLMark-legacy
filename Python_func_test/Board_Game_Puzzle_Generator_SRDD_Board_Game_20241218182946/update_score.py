def update_score(self, difficulty, elapsed_time):
        '''
        Update the score based on difficulty and elapsed time.
        '''
        base_score = {f'easy': 10, f'medium': 20, f'hard': 30}
        time_penalty = elapsed_time // 10
        self.score += max(base_score[difficulty] - time_penalty, 0)