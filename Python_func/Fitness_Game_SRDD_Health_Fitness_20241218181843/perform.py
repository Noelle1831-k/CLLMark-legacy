def perform(self):
        '''
        Simulates the performance of the exercise and returns points based on performance.
        '''
        performance = random.randint(1, 10) * self.difficulty
        return performance