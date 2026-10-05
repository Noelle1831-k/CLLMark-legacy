def run(self):
        running = True
        while running:
            self.input_handler.process_input(self.cars)
            self.physics_engine.update(self.cars, self.track)
            self.graphics_engine.render(self.cars, self.track)
            winner = self.race_manager.check_winner()
            if winner:
                print(f"The winner is {winner.name}!")
                running = False
            time.sleep(0.016)  # Simulate 60 FPS