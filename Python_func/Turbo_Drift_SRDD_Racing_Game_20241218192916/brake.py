def brake(self):
        """
        Reduces the car's speed, ensuring it does not drop below zero.
        """
        self.speed = max(0, self.speed - 5)