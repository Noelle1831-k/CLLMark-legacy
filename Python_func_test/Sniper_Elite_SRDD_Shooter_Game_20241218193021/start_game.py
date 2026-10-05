def start_game(self):
        print("Starting Sniper Elite Game...")
        self.mission.generate_mission()
        while not self.mission.is_completed():
            self.sniper.aim()
            self.sniper.shoot()
            self.mission.evaluate_mission()
        self.end_game()