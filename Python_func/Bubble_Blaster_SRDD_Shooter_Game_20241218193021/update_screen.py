def update_screen(self):
        self.screen.fill((255, 255, 255))
        self.blaster.draw()
        for bubble in self.bubbles:
            bubble.draw()
        for falling_bubble in self.falling_bubbles:
            falling_bubble.draw()
        for power_up in self.power_ups:
            power_up.draw()
        pygame.display.flip()
        self.clock.tick(60)