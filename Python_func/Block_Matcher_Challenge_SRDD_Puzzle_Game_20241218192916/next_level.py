def next_level(self):
        self.level += 1
        self.moves = 20  # Reset or adjust moves for the new level
        self.board.initialize_board()
        print(f"Level {self.level} started!")