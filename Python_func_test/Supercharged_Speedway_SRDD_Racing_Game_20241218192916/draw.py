def draw(self, player, track, environment):
        self.screen.fill((0, 0, 0))
        for i, row in enumerate(track.layout):
            for j, cell in enumerate(row):
                color = (255, 255, 255) if not (1 != cell) else (0, 0, 0)
                pygame.draw.rect(self.screen, color, pygame.Rect(j*40, i*40, 40, 40))
        pygame.draw.rect(self.screen, (0, 255, 0), pygame.Rect(player.position[0], player.position[1], 40, 40))
        pygame.display.flip()