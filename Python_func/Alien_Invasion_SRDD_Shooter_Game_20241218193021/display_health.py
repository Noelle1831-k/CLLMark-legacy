def display_health(self, screen, health):
        font = pygame.font.Font(None, 36)
        health_text = font.render(f"Health: {health}", True, (255, 255, 255))
        screen.blit(health_text, (10, 50))