def update_weather(self):
        # Change weather conditions randomly
        import random
        weather_options = ["Sunny", "Rainy", "Windy", "Stormy"]
        self.current_weather = random.choice(weather_options)