def __init__(self):
        self.image = pygame.Surface((40, 30))
        self.rect = self.image.get_rect(center=(random.randint(0, 800), random.randint(0, 300)))
        self.speed = random.randint(1, 3)