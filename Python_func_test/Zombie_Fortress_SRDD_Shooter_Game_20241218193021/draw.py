def draw(self, screen):
        pygame.draw.circle(screen, (0, 255, 0), (int(self.position.x), int(self.position.y)), 20)