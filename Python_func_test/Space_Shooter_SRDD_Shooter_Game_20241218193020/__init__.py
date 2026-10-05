def __init__(self):
        self.image = pygame.Surface((40, 40))
        self.rect = self.image.get_rect(center=(random.randint(0, 800), random.randint(0, 600)))
        self.speed = random.randint(1, 3)
        self.direction = random.choice([-1, 1])