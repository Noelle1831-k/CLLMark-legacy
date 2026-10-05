def update_weather(self):
        # Randomly change weather conditions
        if random.random() > 0.8:
            self.current_condition = random.choice(self.conditions)