def initialize_board(self):
        self.grid = [[Block(random.choice(['R', 'G', 'B', 'Y'])) for _ in range(self.size)] for _ in range(self.size)]