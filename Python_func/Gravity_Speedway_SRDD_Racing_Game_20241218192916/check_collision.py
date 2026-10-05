def check_collision(self, vehicles):
        collision_count = 0
        for vehicle in vehicles:
            for obs in self.obstacles:
                if obs.check_collision(vehicle):
                    # Handle collision, e.g., reduce speed or reset position
                    vehicle.velocity = [0, 0]  # Stop the vehicle on collision
                    vehicle.position = [0, 0]  # Reset position to start
                    collision_count += 1
        return collision_count