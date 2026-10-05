def generate_challenge(self):
        '''
        Generates a new challenge with random difficulty.
        '''
        self.difficulty = random.randint(1, 10)
        print(f"Challenge generated with difficulty: {self.difficulty}")