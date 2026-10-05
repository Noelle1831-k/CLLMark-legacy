def start_game(self, clock):
        print("Starting the game...")
        self.mission.start_mission()
        while self.is_running:
            self.process_input()
            self.update_state()
            self.render()
            clock.tick(60)