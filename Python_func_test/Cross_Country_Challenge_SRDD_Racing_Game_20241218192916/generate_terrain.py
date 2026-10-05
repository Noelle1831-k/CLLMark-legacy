def generate_terrain(self):
        return [Obstacle() for _ in range(random.randint(5, 15))]