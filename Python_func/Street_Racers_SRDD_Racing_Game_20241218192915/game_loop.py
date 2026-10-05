def game_loop(self):
        while self.running:
            self.input_handler.process_input(self.cars[0])
            for car in self.cars:
                AIController.control_car(car, self.track)
                self.physics.update_physics(car, self.track)
            self.law_enforcement.update(self.cars)
            self.graphics.render(self.cars, self.track)
            time.sleep(0.016)  # Simulate 60 FPS