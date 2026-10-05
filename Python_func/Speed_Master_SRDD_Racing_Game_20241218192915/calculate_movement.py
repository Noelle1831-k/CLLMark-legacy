def calculate_movement(self, vehicle, track):
        base_movement = vehicle.speed * (1 - track.difficulty / 100)
        handling_factor = vehicle.handling / 100
        boost_factor = vehicle.boost / 100
        total_movement = base_movement * handling_factor * boost_factor
        return total_movement