def initialize_board(self):
        self.grid = [[Block() for _ in range(self.size)] for _ in range(self.size)]
        while self.find_matches():  # Ensure no initial matches
            self.grid = [[Block() for _ in range(self.size)] for _ in range(self.size)]