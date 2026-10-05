def update_game_state(self):
        for car in self.cars:
            car.update_position()
            self.physics_engine.update_velocity(car)
        self.ai.update_ai_state(self.cars)
        self.ui.update_ui()