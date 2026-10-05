def initialize_game(self):
        self.load_tracks()
        self.create_players()
        self.select_track()
        self.weather_system.initialize_weather()
        self.select_game_mode()