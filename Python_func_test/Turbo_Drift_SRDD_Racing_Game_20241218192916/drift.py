def drift(self):
        """
        Adjusts the drift angle based on the car's speed and handling.
        """
        self.drift_angle += 10 * self.handling