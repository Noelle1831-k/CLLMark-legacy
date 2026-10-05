def update(self):
        time_elapsed = self.clock.get_time() / 1000.0  # Time in seconds
        for player in self.players:
            player.control_vehicle()
            player.vehicle.update_position(self.physics_engine)
            collisions = self.track.check_collision(self.vehicles)
            player.update_score(time_elapsed, collisions)