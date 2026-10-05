def run(self):
        self.vehicle = vehicle.select_vehicle()
        self.track = track.select_track()
        self.start_time = time.time()
        while self.running:
            self.update()
            self.render()
            if self.vehicle.position >= self.track.length:
                self.running = False
        self.end_time = time.time()
        self.display_results()