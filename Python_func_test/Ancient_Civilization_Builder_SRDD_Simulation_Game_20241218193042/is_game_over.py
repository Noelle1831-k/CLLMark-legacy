def is_game_over(self):
        if self.civilization.population <= 0:
            print("Game Over: Your civilization's population has perished.")
            return True
        if self.civilization.resource_manager.resources.get('food', 0) <= 0:
            print("Game Over: Your civilization has run out of food.")
            return True
        if self.time_period.current_period >= 100:  # Example maximum time period
            print("Game Over: You have reached the maximum time period.")
            return True
        return False