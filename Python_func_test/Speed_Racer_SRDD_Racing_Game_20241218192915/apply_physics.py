def apply_physics(self, player, track):
        # Simulate physics for the player's vehicle
        player.vehicle.speed -= track.length * 0.001
        player.vehicle.speed = max(player.vehicle.speed, 0)  # Ensure speed doesn't go negative