def initialize(self):
        self.track = track.Track()
        self.track.generate_track()
        self.vehicles = [vehicle.Vehicle() for _ in range(5)]
        self.players = [player.Player(v) for v in self.vehicles]
        self.running = True