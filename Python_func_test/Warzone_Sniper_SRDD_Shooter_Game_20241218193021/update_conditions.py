def update_conditions(self):
        # Randomly update wind conditions for more dynamic gameplay
        self.wind_speed = random.uniform(0, 20)  # Wind speed in m/s
        self.wind_direction = random.uniform(0, 360)  # Wind direction in degrees
        print(f"Updating environmental conditions: Wind Speed = {self.wind_speed}, Wind Direction = {self.wind_direction}")