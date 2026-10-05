def handle_collision(self, car):
        # Apply a more realistic collision response
        car.velocity[0] = -0.5 * car.velocity[0]  # Reduce speed and invert direction
        car.velocity[1] = -0.5 * car.velocity[1]
        # Displace the car slightly to prevent getting stuck
        car.position[0] += car.velocity[0]
        car.position[1] += car.velocity[1]
        # Play collision sound
        self.sound_engine.play_collision_sound()