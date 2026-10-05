def activate(self, current_time, player):
        super().activate(current_time)
        if self.active:
            player.invincible = True
            print(f"{player.name} is now invincible for {self.duration} seconds")