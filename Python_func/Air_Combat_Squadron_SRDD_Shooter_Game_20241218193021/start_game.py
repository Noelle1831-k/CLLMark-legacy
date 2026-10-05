def start_game(self):
        print("Initializing game...")
        self.current_mission = mission.Mission()
        self.current_mission.load_mission()
        self.run_game_loop()