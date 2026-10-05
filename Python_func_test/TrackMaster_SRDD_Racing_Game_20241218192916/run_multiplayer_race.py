def run_multiplayer_race(self):
        '''
        Handles the multiplayer race logic.
        '''
        threads = []
        for player in self.connected_players:
            thread = threading.Thread(target=self.simulate_player_race, args=(player,))
            threads.append(thread)
            thread.start()
        for thread in threads:
            thread.join()