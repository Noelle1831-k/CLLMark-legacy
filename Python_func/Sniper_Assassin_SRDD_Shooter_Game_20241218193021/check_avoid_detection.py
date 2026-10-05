def check_avoid_detection(self, environment):
        if not environment.player_detected:
            self.objectives["avoid_detection"] = True