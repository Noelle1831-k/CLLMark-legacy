def start_championship(self):
        for race in self.races:
            results = race.conduct_race()
            self.update_standings(results)
        self.display_final_standings()