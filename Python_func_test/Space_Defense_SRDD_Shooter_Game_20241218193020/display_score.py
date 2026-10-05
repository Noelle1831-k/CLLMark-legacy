def display_score(self, screen):
        font = pygame.font.Font(None, 36)
        score_text = font.render('Score: 100', True, (255, 255, 255))
        screen.blit(score_text, (10, 10))