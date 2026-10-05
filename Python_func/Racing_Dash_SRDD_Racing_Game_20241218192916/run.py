def run(self):
        while self.running:
            self.controls.process_input(self.player_car, self.stop_game)
            self.update()
            self.render()