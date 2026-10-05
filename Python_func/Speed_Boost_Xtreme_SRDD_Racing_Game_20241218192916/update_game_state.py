def update_game_state(self):
        self.car.accelerate()
        if self.track.check_collision(self.car):
            self.car.brake()
        if self.speed_boost.activate_boost(self.car):
            self.car.boost()
        else:
            self.car.deactivate_boost()