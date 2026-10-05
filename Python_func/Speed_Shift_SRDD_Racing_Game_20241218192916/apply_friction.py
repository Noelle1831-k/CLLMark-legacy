def apply_friction(self, vehicle, track):
        friction_factor = 0.98 if track.difficulty == "Hard" else 0.99
        vehicle.current_speed *= friction_factor