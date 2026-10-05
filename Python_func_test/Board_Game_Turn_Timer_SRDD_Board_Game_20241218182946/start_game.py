def start_game(self):
        '''
        Starts the game loop with user control to stop the game.
        '''
        while True:
            current_player = self.players[self.current_player_index]
            print(f"{current_player.name}'s turn")
            self.timer.start()
            self.next_turn()
            # Allow user to stop the game
            command = input("Enter 'q' to quit or press Enter to continue: ").strip().lower()
            if command == 'q':
                print("Game ended by user.")
                break