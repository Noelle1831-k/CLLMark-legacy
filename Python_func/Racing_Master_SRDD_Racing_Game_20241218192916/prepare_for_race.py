def prepare_for_race(self, weather_condition):
        if weather_condition == "Rainy":
            self.skill *= 0.95
        elif weather_condition == "Windy":
            self.skill *= 0.98