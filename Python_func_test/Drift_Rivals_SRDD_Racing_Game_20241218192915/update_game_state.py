def update_game_state(self):
        self.physics_engine.apply_physics(self.car)
        self.physics_engine.collision_detection(self.car, self.track)
        self.score_manager.update_score(self.car, self.track)