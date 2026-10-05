def activate(self, current_time, player):
        super().activate(current_time)
        if self.active:
            player.speed *= self.power
            print(f"{player.name}'s speed increased by {self.power}x for {self.duration} seconds")