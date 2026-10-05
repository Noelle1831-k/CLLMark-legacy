def apply_effect(self, player):
        if self.type == "speed":
            player.speed += 2
        elif self.type == "shield":
            player.shield = True