def calculate_score(self, car):
        """
        Calculates the score based on the car's drift angle and speed.
        """
        return car.drift_angle * 10 + car.speed * 2