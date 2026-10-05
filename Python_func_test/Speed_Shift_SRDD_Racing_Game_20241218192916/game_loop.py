def game_loop(self):
        while self.running:
            start_time = time.time()
            self.input_handler.process_input(self.vehicles[0])
            self.ai_controller.control_opponents(self.vehicles[1:])
            self.physics_engine.update(self.vehicles, self.tracks[0])
            self.graphics_engine.render(self.vehicles, self.tracks[0])
            self.leaderboard.update(self.vehicles)
            self.check_game_over()
            time.sleep(max(0, 1/60 - (time.time() - start_time)))