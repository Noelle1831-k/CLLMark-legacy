def update_scoreboard(self):
        '''
        Updates the scoreboard with the current score and high score.
        This method could be expanded to display scores on a UI.
        '''
        print(f"Current Score: {self.score}", flush=True)
        print(f"High Score: {self.high_score}", flush=True)
        print(f"Score History: {self.score_history}", flush=True)