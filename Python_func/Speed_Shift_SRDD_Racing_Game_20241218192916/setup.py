def setup(self):
        self.tracks.append(Track("Desert Dash", 5000, "Hard"))
        self.vehicles.append(Vehicle("Speedster", 200, 5, 0.8))
        self.vehicles.append(Vehicle("Thunderbolt", 220, 6, 0.7))
        self.sound_engine.play_background_music()