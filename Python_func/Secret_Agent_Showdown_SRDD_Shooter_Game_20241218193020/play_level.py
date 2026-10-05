def play_level(self, level):
        '''
        Play through the current level.
        '''
        while not level.check_objectives():
            self.player_action()
            level.update_enemies(self.player)
        level.complete_level()
        self.current_level += 1