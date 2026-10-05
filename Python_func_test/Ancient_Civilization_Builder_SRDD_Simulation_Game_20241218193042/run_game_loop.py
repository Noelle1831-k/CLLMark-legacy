def run_game_loop(self):
        while not self.is_game_over():
            self.time_period.advance_time()
            self.challenges = self.time_period.get_challenges()
            for challenge in self.challenges:
                challenge.apply_impact(self.civilization)
            self.civilization.manage_resources()
            self.civilization.make_decision()
            self.display_status()
        self.end_game()