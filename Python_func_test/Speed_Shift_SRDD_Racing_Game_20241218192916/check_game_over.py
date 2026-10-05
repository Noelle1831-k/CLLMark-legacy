def check_game_over(self):
        if any(vehicle.position >= self.tracks[0].length for vehicle in self.vehicles):
            self.running = False
            self.sound_engine.play_victory_sound()
            self.leaderboard.display()