def generate_dungeon(self, size=5):
        '''
        Generates a dungeon layout with random puzzles.
        '''
        self.layout = [[random.choice(["puzzle", "empty", "treasure"]) for _ in range(size)] for _ in range(size)]
        self.current_room = (0, 0)