def render_track(self, graphics_renderer):
        # Render all obstacles on the track
        for obs in self.obstacles:
            obs.render(graphics_renderer)