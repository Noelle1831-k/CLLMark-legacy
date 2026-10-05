def play_season(self):
        for match in self.matches:
            self.set_team_strategies()
            match.play_match()
            match.analyze_performance()
            self.negotiate_contracts()
        self.end_game()