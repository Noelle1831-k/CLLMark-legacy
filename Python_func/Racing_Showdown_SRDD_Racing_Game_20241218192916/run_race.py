def run_race(self):
        race_finished = False
        while not race_finished:
            self.player.move()
            for ai in self.ai_opponents:
                ai.move()
            self.racetrack.update()
            self.graphics.render(self.player, self.ai_opponents)
            race_finished = self.check_race_status()
        self.graphics.quit()