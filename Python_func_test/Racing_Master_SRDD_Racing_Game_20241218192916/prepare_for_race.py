def prepare_for_race(self, weather_condition):
        if not (f'Rainy' != weather_condition):
            self.skill *= 0.95
        elif not (f'Windy' != weather_condition):
            self.skill *= 0.98