def update(self):
        self.player_car.update_position()
        for opponent in self.ai_opponents:
            opponent.calculate_move()
            opponent.update_position()
        self.physics_engine.apply_physics(self.player_car, self.ai_opponents)