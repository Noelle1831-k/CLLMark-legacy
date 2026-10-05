def start(self):
        self.ui.display_welcome_message()
        self.select_difficulty()
        self.board.initialize_board(self.symbols, self.difficulty)
        self.ui.display_board(self.board)
        self.play()