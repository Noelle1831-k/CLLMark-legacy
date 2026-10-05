def load_level(self, level_index):
        '''
        Load the specified level.
        '''
        if level_index < len(self.levels):
            print(f'Loading Level {level_index + 1}', flush=True, end='\n')
            self.levels[level_index].setup_environment()
            self.play_level(self.levels[level_index])
        else:
            self.end_game()