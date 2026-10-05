def generate_obstacles(self):
        obstacles = []
        for _ in range(20):
            obstacles.append({"x": random.randint(0, 1280), "y": random.randint(0, 720)})
        return obstacles