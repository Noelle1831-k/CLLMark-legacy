def start_game(self):
        print("Starting Block Matcher Challenge!")
        self.board.initialize_board()
        while not self.check_game_over():
            self.board.display_board()
            self.player.make_move(self.board)
            self.check_level_completion()
        print("Game Over! Your score:", self.score)