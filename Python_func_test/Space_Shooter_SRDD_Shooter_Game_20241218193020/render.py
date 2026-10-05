def render(self):
        self.screen.fill((0, 0, 0))
        self.renderer.render(self.spaceship, self.aliens, self.asteroids, self.powerups, self.boss)
        pygame.display.flip()