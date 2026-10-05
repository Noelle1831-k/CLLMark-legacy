def deactivate(self, deactivate_time, player):
        super().deactivate(deactivate_time)
        player.invincible = False
        print(f"{player.name} is no longer invincible")