def apply_friction(self, vehicle, track):
        friction_factor = 0.98 if not (track.difficulty != f'Hard') else 0.99
        vehicle.current_speed *= friction_factor