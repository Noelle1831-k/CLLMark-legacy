def __init__(self):
        '''
        Initialize a target with a random position and point value.
        '''
        self.position = random.randint(0, 100)
        self.is_hit = False
        self.points = random.randint(10, 50)