def run_game_loop(self):
        while not self.current_mission.is_completed():
            self.current_mission.update()
            self.handle_input()
            self.render()
        self.end_game()