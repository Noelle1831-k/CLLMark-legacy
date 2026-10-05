def setup_game(self, rifle_choice):
        '''
        Sets up the game with initial configurations such as rifle selection.
        '''
        print("Setting up the game...")
        self.sniper.rifle.select_rifle(rifle_choice)