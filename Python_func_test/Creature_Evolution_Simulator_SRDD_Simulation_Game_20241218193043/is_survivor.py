def is_survivor(self, environment):
        survival_chance = (self.health + self.speed + self.camouflage) / 3
        environmental_pressure = (environment.temperature + environment.food_availability) / 2
        return survival_chance > environmental_pressure