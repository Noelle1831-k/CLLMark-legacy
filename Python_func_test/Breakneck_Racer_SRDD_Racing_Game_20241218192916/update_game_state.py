def update_game_state(self, delta_time):
        self.apply_physics(delta_time)
        self.active_car.apply_physics(delta_time)
        self.detect_collisions()