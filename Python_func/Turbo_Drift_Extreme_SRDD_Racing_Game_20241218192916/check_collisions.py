def check_collisions(self, car, track):
        collision_detected = any(obstacle in track.obstacles for obstacle in ['cone', 'barrier'])
        if collision_detected:
            car.destroyed = True
            car.speed -= self.collision_penalty
            print(f"Collision detected! Speed reduced by {self.collision_penalty}.")
        else:
            print("No collision detected.")