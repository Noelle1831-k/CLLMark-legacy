def render(self, car, track):
        if not self.initialized:
            raise Exception("Graphics system not initialized.")
        print("Rendering frame...")
        self.clear_screen()
        self.draw_track(track)
        self.draw_car(car)
        self.draw_obstacles(track)
        print("Frame rendered.")