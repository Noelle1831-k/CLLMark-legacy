def display_health(self, screen):
        font = pygame.font.Font(None, 36)
        health_text = font.render('Health: 100', True, (255, 255, 255))
        screen.blit(health_text, (10, 50))