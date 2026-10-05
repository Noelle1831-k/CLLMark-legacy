def generate_track(self):
        '''
        Generates a track with random obstacles placed at various points.
        '''
        num_obstacles = random.randint(5, 15)  # Random number of obstacles
        for _ in range(num_obstacles):
            position = random.randint(100, self.length - 100)  # Avoid placing obstacles too close to start or end
            size = random.randint(1, 3)  # Random size of the obstacle
            self.obstacles.append((position, size))
        print(f"Track generated with {len(self.obstacles)} obstacles.")