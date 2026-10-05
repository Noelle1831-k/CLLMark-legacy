def start_game(self):
        print("Starting the TeamManager game...")
        self.create_teams()
        self.schedule_matches()
        self.play_season()