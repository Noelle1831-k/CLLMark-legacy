def render(self):
        self.graphics_renderer.draw_terrain(self.terrain)
        for vehicle in self.vehicles:
            self.graphics_renderer.draw_vehicle(vehicle)