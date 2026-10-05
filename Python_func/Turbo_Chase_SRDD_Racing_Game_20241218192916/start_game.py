def start_game(self):
        self.city.generate_city_map()
        self.vehicle = self.player.choose_vehicle()
        self.graphics.render_scene()
        while not self.is_game_over():
            self.update_game_state()
            self.graphics.update_graphics()
        self.end_game()