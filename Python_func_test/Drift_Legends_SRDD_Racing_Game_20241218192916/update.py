def update(self):
        for car in self.cars:
            car.update()
            self.physics_engine.apply_physics(car)
            self.score_system.update_score(car)