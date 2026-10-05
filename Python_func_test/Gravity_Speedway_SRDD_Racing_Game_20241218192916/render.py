def render(self):
        self.graphics_renderer.render_background()
        self.track.render_track(self.graphics_renderer)
        for index, vehicle in enumerate(self.vehicles):
            self.graphics_renderer.render_vehicle(vehicle, index)
        for player in self.players:
            player.display_score(self.graphics_renderer)
        self.graphics_renderer.update_display()