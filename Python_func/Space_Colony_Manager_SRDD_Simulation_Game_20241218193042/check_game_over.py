def check_game_over(self):
        if self.colony.is_threatened() or self.colony.is_self_sustaining():
            self.game_over = True