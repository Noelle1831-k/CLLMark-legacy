def render(self):
        '''
        Renders the arena and its obstacles.
        '''
        print(f"Rendering arena of size: {self.size}")
        for obstacle in self.obstacles:
            print(f"Obstacle at {obstacle['position']} with size {obstacle['size']}")