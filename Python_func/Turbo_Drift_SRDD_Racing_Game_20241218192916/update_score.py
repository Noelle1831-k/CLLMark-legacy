def update_score(self, car):
        """
        Updates the score based on the car's current state.
        """
        self.score += self.calculate_score(car)
        print(f"Current score: {self.score}")