def change_conditions(self, temperature_change, food_change, predator_change):
        self.temperature += temperature_change
        self.food_availability += food_change
        self.predator_density += predator_change