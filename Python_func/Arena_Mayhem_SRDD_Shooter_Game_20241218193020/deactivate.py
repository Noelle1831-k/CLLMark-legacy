def deactivate(self, player):
        if self.name == "Speed Boost":
            player.speed_multiplier /= self.effect
            self.active = False
            print(f"{player.name}'s Speed Boost has worn off. Speed multiplier reset to {player.speed_multiplier}")
        elif self.name == "Shield":
            player.health -= self.effect
            self.active = False
            print(f"{player.name}'s Shield has worn off. Health reset to {player.health}")