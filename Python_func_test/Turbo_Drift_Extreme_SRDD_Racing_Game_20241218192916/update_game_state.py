def update_game_state(self):
        self.physics_engine.update_physics(self.car, self.track)
        self.score_system.update_score(self.car)