def start_game(self):
        self.ui.display_menu()
        self.track.load_track()
        self.initialize_cars()
        while self.running:
            self.update_game_state()
            self.graphics_engine.update_display(self.cars)