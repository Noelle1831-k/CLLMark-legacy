def start_game(self):
        '''
        Start the game by simulating traffic and evaluating player performance.
        '''
        print("Starting the City Traffic Manager game...")
        self.city.simulate_traffic()
        self.evaluate_performance()