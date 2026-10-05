def render(self, player: Player, ai_opponents: list):
        # Render the game frame
        self.screen.blit(self.background, (0, 0))
        self.render_track()
        self.render_vehicles(player, ai_opponents)
        pygame.display.flip()
        self.clock.tick(60)  # Limit to 60 frames per second