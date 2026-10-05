def validate_rule(self, player_solution):
        # Validate the player's solution against the hidden rule
        expected_solution = self.apply_rule()
        return player_solution == expected_solution