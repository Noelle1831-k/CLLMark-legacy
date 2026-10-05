def apply_gravity(self, car):
        # Simulate gravity application logic
        if car.speed > 0:
            car.speed -= 0.1  # Simulate friction slowing down the car