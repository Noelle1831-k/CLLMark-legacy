def play_turn(self, player):
        '''
        Play a single turn for a player.
        '''
        print(f"{player.name}'s turn")
        words_found = self.grid.find_words()
        score = self.calculate_score(words_found)
        player.update_score(score)
        self.leaderboard.update(player)