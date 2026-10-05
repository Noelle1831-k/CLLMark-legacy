def render(self):
        """
        Renders the game components including the car and track.
        """
        print("Rendering game visuals...")
        self.graphics_engine.draw_car(self.car)
        self.track.render_track()