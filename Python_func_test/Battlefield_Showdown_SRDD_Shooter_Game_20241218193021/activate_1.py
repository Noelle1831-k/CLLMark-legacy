def activate(self, current_time, player):
        super().activate(current_time)
        if self.active:
            player.health = min(100, player.health + self.power)
            print(f"{player.name} healed by {self.power}. Current health: {player.health}")