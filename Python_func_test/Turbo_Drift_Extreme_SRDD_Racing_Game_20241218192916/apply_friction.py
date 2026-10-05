def apply_friction(self, car):
        friction_force = self.friction_coefficient * self.gravity * car.speed
        car.speed = car.speed - friction_force / 100
        print(f"Applying friction: {friction_force}, new speed: {car.speed}")