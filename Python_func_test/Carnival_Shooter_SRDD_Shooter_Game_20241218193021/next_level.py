def next_level(self):
        '''
        Proceed to the next level if available, otherwise end the game.
        '''
        if self.current_level < len(self.levels):
            level = self.levels[self.current_level]
            level.load_level()
            while not level.check_completion():
                self.player_action(level)
            self.current_level += 1
            self.ui.display_level_complete(self.current_level)
            self.next_level()
        else:
            self.ui.display_game_over(self.player.score)