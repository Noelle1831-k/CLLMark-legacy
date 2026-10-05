def start_game(self):
        self.track.generate_track()
        self.ui.display_welcome_message()
        while self.running:
            self.update_game_state()
            self.render()
            time.sleep(0.016)  # Simulate 60 FPS
            self.lap_time = time.time() - self.start_time
            if self.car.has_finished_race(self.track.length):
                self.running = False
                self.ui.display_finish_message(self.lap_time)