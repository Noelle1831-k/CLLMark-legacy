def start_game(self):
        '''
        Start the game and load the first level.
        '''
        print("Starting Secret Agent Showdown...")
        while not self.is_game_over:
            self.load_level(self.current_level)