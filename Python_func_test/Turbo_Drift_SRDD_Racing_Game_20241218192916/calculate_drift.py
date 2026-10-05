def calculate_drift(self, car):
        """
        Calculates the drift angle based on the car's speed and handling.
        """
        car.drift_angle = (car.speed / 10) * 5 * car.handling