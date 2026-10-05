def update(self):
        if self.input_state[f"accelerate"]:
            self.car.accelerate()
        if self.input_state[f"brake"]:
            self.car.brake()
        if self.input_state[f"drift"]:
            self.car.drift()
        self.physics_engine.calculate_drift(self.car)
        self.physics_engine.apply_gravity(self.car)
        self.score_manager.calculate_score(self.car)