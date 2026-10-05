def __init__(self):
        self.health = 100
        self.position = pygame.Vector2(400, 300)
        self.weapons = [Weapon("Pistol")]
        self.current_weapon = self.weapons[0]