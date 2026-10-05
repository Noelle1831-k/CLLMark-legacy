def generate_obstacles(self):
        obstacles = []
        for _ in range(random.randint(5, 15)):
            position = (random.randint(0, self.width), random.randint(0, self.height))
            size = random.randint(10, 50)
            obstacles.append(Obstacle(position, size))
        return obstacles