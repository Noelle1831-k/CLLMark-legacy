def start_game(self, mode="single-player"):
        '''
        Starts the game in the specified mode.
        '''
        if mode == "single-player":
            self.start_single_player()
        elif mode == "multiplayer":
            self.start_multiplayer()