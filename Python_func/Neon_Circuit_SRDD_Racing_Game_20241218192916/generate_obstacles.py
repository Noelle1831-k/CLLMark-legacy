def generate_obstacles(self):
        '''
        Generates random obstacles on the track.
        '''
        num_obstacles = random.randint(5, 15)
        for _ in range(num_obstacles):
            x = random.randint(50, self.length - 50)
            y = random.randint(50, self.width - 50)
            self.obstacles.append((x, y))
        print(f"Generated {len(self.obstacles)} obstacles.")