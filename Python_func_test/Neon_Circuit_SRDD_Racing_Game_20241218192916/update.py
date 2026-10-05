def update(self):
        self.handle_input()
        self.physics.calculate_velocity(self.vehicle)
        collision = self.physics.detect_collision(self.vehicle, self.track)
        if collision:
            self.audio.play_sound("collision.wav")
            self.running = False
        self.graphics.draw_track(self.track)
        self.graphics.draw_vehicle(self.vehicle)
        self.ui.display_score(self.score)
        self.score += 1