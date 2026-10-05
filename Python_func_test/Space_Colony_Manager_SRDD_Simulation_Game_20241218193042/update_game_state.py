def update_game_state(self):
        self.colony.manage_resources()
        challenges = self.planet.get_challenges()
        for challenge in challenges:
            self.decision_maker.make_decision(challenge)
        self.check_game_over()