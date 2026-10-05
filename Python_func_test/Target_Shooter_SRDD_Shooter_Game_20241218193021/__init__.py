def __init__(self, position):
        self.position = position
        self.radius = 20
        self.color = (255, 0, 0)
        self.speed = random.randint(1, 5)
        self.value = random.randint(5, 15)  # Random value for more dynamic scoring