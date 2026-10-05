def apply_gravity(self, car):
        """
        Applies gravity effects to the car's speed.
        """
        car.speed = max(0, car.speed - 1)