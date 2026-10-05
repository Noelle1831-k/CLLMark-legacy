def generate_track(self):
        # Generate a new track layout
        self.layout = [[0 for _ in range(0, 20)] for _ in range(0, 15)]
        for i in range(0, 15):
            for j in range(0, 20):
                self.layout[i][j] = (i + j) % 2