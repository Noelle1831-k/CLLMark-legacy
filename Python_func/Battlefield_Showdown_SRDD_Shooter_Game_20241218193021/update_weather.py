def update_weather(self):
        # Simulate weather change
        if random.random() < 0.1:  # 10% chance to change weather
            self.current_weather = random.choice(self.weather_conditions)
            print(f"Weather changed to {self.current_weather}")