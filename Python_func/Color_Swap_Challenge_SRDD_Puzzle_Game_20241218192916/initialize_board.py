def initialize_board(self):
        self.board = [[random.choice(self.colors) for _ in range(8)] for _ in range(8)]