def generate_obstacles(self):
        print("Generating Obstacles...")
        return [f"Obstacle-{i}" for i in range(self.complexity * 3)]