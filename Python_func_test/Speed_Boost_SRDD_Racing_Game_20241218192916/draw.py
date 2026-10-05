def draw(self, player, track):
        self.screen.fill((0, 0, 0))
        pygame.draw.circle(self.screen, (0, 255, 0), (int(player.position.x), int(player.position.y)), player.size)
        track.render(self.screen)