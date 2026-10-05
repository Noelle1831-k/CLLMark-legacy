def generate(self, level):
        '''
        Generate a grid based on the level.
        '''
        size = level + 4
        self.grid = [[random.choice(string.ascii_uppercase) for _ in range(size)] for _ in range(size)]
        self.display()