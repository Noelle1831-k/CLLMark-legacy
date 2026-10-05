def start(self):
        self.graphics.initialize()
        self.player.choose_vehicle()
        self.racetrack.setup()
        for ai in self.ai_opponents:
            ai.select_vehicle()
        self.graphics.load_assets(self.player, self.ai_opponents, self.racetrack)
        self.run_race()