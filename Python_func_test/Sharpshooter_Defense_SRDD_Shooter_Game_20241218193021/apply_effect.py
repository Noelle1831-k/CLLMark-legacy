def apply_effect(self, player):
        if self.effect == "health":
            player.health += 20
            print("Player health increased by 20")
        elif self.effect == "ammo":
            for weapon in player.inventory:
                weapon.ammo += 5
            print("Player ammo increased by 5 for each weapon")