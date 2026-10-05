def render_graphics(self):
        self.graphics_engine.draw_track(self.track)
        self.graphics_engine.draw_car(self.car)
        self.score_manager.display_score()