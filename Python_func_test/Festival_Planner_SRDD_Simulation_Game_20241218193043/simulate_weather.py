def simulate_weather(self):
        '''
        Simulates weather conditions for the festival.
        '''
        self.weather = choice(["Sunny", "Rainy", "Cloudy", "Stormy"])
        print(f"Today's Weather: {self.weather}")