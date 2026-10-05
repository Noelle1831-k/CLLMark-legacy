def run_lap(self):
        for opponent in self.opponents:
            opponent.accelerate()
        self.player_vehicle.accelerate()
        self.player_vehicle.drift()
        self.check_collisions()