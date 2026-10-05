def update(self, vehicles, track):
        for vehicle in vehicles:
            vehicle.update_position()
            self.apply_friction(vehicle, track)