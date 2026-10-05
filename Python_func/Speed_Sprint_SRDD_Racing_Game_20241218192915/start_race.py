def start_race(self):
        print("Race started!")
        self.track.generate_track()
        while not self.race_finished:
            self.update_game_state()
            self.graphics.render(self.vehicle, self.track)
            self.controls.process_input()