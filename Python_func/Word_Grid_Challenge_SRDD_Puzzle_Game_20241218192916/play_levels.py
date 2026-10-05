def play_levels(self):
        '''
        Play through the levels of the game.
        '''
        level = 1
        while True:
            print(f"Starting Level {level}")
            self.grid.generate(level)
            self.timer.start()
            for player in self.players:
                self.play_turn(player)
            self.timer.stop()
            if not self.next_level():
                break
            level += 1