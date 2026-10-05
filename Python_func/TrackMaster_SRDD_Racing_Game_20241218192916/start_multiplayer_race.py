def start_multiplayer_race(self):
        '''
        Starts a multiplayer race.
        '''
        if len(self.connected_players) > 1:
            print("Multiplayer race started!")
            self.run_multiplayer_race()
        else:
            print("Not enough players for multiplayer race.")