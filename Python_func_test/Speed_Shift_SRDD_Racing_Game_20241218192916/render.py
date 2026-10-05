def render(self, vehicles, track):
        for vehicle in vehicles:
            self.draw_vehicle(vehicle)
        self.draw_track(track)