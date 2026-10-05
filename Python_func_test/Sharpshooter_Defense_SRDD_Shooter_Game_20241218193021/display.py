def display(self):
        print("Displaying game UI")
        self.game.start_game()
        while self.game.is_running:
            self.handle_input()