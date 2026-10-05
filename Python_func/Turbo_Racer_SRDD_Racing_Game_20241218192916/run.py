def run(self):
        while self.running:
            self.running = self.input_handler.process_inputs(self.players)
            self.physics.update(self.players, self.track)
            self.graphics.render(self.players, self.track)
            time.sleep(1/60)  # Run at 60 FPS