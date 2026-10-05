def upgrade(self, additional_power, reduced_cooldown):
        self.power += additional_power
        self.cooldown = max(0, self.cooldown - reduced_cooldown)
        print(f"Ability {self.name} upgraded! New power: {self.power}, New cooldown: {self.cooldown:.2f} seconds")