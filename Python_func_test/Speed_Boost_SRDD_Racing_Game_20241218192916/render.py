def render(self, screen):
        for obstacle in self.obstacles:
            obstacle.render(screen)