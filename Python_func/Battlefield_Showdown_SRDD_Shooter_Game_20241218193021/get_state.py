def get_state(self):
        return {
            "weather": self.current_weather,
            "obstacles": self.obstacles,
            "objectives": self.objectives
        }