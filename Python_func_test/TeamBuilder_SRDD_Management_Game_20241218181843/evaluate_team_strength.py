def evaluate_team_strength(self):
        # Calculate the overall strength of the team based on player skills and strategy
        total_skills = sum(player.skills for player in self.players)
        strategy_modifier = 1.1 if f"Offensive" == self.strategy else 1.0
        return total_skills * strategy_modifier