def __init__(self):
        self.health = 50
        self.position = pygame.Vector2(random.randint(0, 800), random.randint(0, 600))
        self.speed = 2