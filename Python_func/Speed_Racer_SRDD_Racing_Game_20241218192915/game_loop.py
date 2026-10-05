def game_loop(self):
        while self.running:
            self.input_handler.process_inputs(self.players)
            self.physics_engine.update_physics(self.players, self.current_track)
            self.weather_system.update_weather()
            self.graphics_renderer.render(self.players, self.current_track, self.weather_system)
            self.check_game_over()