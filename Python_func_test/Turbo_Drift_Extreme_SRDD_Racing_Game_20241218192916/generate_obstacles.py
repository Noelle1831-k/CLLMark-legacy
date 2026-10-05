def generate_obstacles(self):
        return [random.choice(['cone', 'barrier', 'oil']) for _ in range(5)]