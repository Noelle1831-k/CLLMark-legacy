def next_level(self):
        self.level.increase_difficulty()
        self.board.initialize_board()
        print("Level up! Difficulty increased.")