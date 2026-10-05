def generate_obstacles(self):
        '''
        Generates random obstacles within the arena.
        '''
        obstacles = []
        num_obstacles = random.randint(5, 15)
        for _ in range(num_obstacles):
            position = (random.randint(0, self.size[0]), random.randint(0, self.size[1]))
            size = (random.randint(1, 5), random.randint(1, 5))
            obstacles.append({'position': position, 'size': size})
        return obstacles