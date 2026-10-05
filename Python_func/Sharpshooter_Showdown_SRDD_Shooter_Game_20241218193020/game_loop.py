def game_loop(self):
        while self.current_level <= 5:
            print(f"Starting Level {self.current_level}")
            targets = self.levels.get_targets(self.current_level)
            for target in targets:
                self.weapon.shoot(target, self.player)
            self.current_level += 1
            self.levels.load_level(self.current_level)
        self.end_game()