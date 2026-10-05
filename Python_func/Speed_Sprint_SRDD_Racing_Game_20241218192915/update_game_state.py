def update_game_state(self):
        self.vehicle.accelerate()
        self.track.update_position(self.vehicle.speed)
        self.player.update_performance()
        if self.track.is_finished():
            print("Race finished! Congratulations!")
            self.race_finished = True