def draw_scores(self, screen):
        '''
        Draw the scores of all players on the screen.
        '''
        font = pygame.font.Font(None, 36)
        y_offset = 10
        for player, score in self.scores.items():
            score_text = font.render(f"Player {self.players.index(player) + 1}: {score}", True, (255, 255, 255))
            screen.blit(score_text, (10, y_offset))
            y_offset += 40