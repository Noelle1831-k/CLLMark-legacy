def start_game(self):
        print("Welcome to Sniper Assassin!")
        for mission in self.missions:
            self.current_mission = mission
            self.current_mission.load_mission()
            self.environment.generate_challenges()
            while not self.current_mission.complete_mission(self.player, self.environment):
                self.player.aim()
                self.player.shoot()
                self.environment.update_environment()
            print(f"Mission {mission.id} completed!")
        self.end_game()