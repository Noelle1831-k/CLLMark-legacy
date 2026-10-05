def apply(self, player):
        if self.name == "Health Boost":
            player.health += self.effect
            print(f"{player.name} received a Health Boost of {self.effect}. Current health: {player.health}")
        elif self.name == "Speed Boost":
            self.duration = 5
            self.active = True
            player.speed_multiplier *= self.effect
            print(f"{player.name} received a Speed Boost. Speed multiplier: {player.speed_multiplier}")
        elif self.name == "Shield":
            self.duration = 3
            self.active = True
            player.health += self.effect
            print(f"{player.name} received a Shield. Temporary health: {player.health}")