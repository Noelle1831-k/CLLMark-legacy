def check_game_over(self):
        if self.car.is_destroyed() or self.track.is_completed():
            self.running = False
            self.end_game()