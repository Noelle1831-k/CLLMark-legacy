def start_game(self):
        print("Starting Sniper Squad Showdown...")
        self.load_players()
        self.load_missions()
        self.run_game_loop()