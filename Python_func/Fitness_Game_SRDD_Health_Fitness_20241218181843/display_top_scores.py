def display_top_scores(self):
        '''
        Displays the top scores on the leaderboard.
        '''
        print("\nLeaderboard:")
        for i, score in enumerate(self.scores[:10], start=1):
            print(f"{i}. {score}")