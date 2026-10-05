def __init__(self, name):
        self.name = name
        self.health = 100
        self.position = [0, 0]  # Changed to list for mutability
        self.weapon = None
        self.speed_multiplier = 1.0
        self.active_powerups = []