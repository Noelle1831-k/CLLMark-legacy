def display_score(self, graphics_renderer):
        # Display the player's score on the screen
        font = pygame.font.Font(None, 36)
        score_text = font.render(f'Score: {self.score}', True, (255, 255, 255))
        graphics_renderer.screen.blit(score_text, (10, 10))