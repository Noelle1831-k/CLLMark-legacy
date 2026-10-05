def start_game(self):
        '''
        Start the game by generating a puzzle and starting the timer.
        '''
        self.generate_puzzle()
        self.timer.start()
        self.solve_puzzle()