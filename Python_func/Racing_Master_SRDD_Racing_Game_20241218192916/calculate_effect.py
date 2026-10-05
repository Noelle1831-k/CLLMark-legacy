def calculate_effect(self):
        if self.condition == "Sunny":
            return 1.0
        elif self.condition == "Rainy":
            return 0.9
        elif self.condition == "Windy":
            return 0.95