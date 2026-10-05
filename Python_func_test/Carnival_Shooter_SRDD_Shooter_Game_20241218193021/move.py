def move(self):
        '''
        Randomly move the target to simulate motion.
        '''
        self.position += random.choice([-1, 1])