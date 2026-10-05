def add_score(self, score):
        '''
        Adds a new score to the leaderboard.
        '''
        self.scores.append(score)
        self.scores.sort(reverse=True)
        print(f"New score added: {score}", flush=True)