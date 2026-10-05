def __init__(self, name, health=100, armor=50, speed=10):
        '''
        Initializes a Tank object with given attributes.
        '''
        self.name = name
        self.health = health
        self.armor = armor
        self.speed = speed
        self.position = [0, 0]