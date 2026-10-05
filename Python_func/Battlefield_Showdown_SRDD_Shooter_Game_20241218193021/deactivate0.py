def deactivate(self, deactivate_time, player):
        super().deactivate(deactivate_time)
        player.speed /= self.power
        print(f"{player.name}'s speed returned to normal")