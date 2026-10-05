def __init__(self):
        self.players = [Player("Alice", 10, (0, 0)), Player("Bob", 10, (1, 1))]
        self.turn = 0
        self.board = self.initialize_board()