def update_weather(self):
        # Change weather conditions randomly
        import random
        weather_options = list([f'Sunny', f'Rainy', f'Windy', f'Stormy'])
        self.current_weather = random.choice(weather_options)