def generate_obstacles(self):
        return [random.randint(0, self.length) for _ in range(50)]