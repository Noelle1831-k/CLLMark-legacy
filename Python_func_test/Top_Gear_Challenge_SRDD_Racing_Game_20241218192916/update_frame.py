def update_frame(self):
        user_input = self.controller.get_input()
        self.vehicle.move_vehicle(user_input)
        self.physics.apply_physics(self.vehicle, self.track)
        if self.puzzle.check_puzzle_trigger(self.vehicle.position):
            solved = self.puzzle.solve_puzzle()
            if solved:
                self.score.add_bonus(100)
        self.graphics.render_frame(self.track, self.vehicle, self.score)
        self.sound_manager.play_effect("engine")
        if self.timer.check_time() == 0:
            self.running = False
            self.end_game()