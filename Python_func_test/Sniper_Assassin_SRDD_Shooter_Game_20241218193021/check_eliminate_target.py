def check_eliminate_target(self, player):
        if player.target_eliminated:
            self.objectives["eliminate_target"] = True