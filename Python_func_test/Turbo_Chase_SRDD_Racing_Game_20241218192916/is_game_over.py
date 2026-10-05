def is_game_over(self):
        if self.player_distance >= self.finish_line:
            print("Congratulations! You've completed the race.")
            self.game_over = True
        elif self.police_distance >= self.player_distance:
            print("You've been caught by the police!")
            self.game_over = True
        return self.game_over