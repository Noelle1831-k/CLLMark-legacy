def render(self):
        self.screen.fill((0, 0, 0))
        self.spaceship.draw(self.screen)
        for alien in self.aliens:
            alien.draw(self.screen)
        self.ui.display_score(self.screen)
        self.ui.display_health(self.screen)
        pygame.display.flip()