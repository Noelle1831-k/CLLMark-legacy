def initialize_game(self):
        self.track.load_track()
        self.car.select_car()
        self.graphics_engine.initialize_graphics()
        self.score_system.reset_score()