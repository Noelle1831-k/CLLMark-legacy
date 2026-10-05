def next_level(self):
        self.current_puzzle = Puzzle(self.level_manager.current_level)
        self.current_puzzle.generate_puzzle()
        self.player.play(self.current_puzzle)
        if self.player.has_solved:
            self.level_manager.increase_difficulty()
            self.next_level()
        else:
            print("Game Over!")