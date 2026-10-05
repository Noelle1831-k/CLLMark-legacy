def start_game(self):
        """
        Starts the main game loop and keeps the game running until exit.
        """
        print("Starting Turbo Drift game...")
        while self.running:
            self.update()
            self.render()
            self.check_exit_condition()