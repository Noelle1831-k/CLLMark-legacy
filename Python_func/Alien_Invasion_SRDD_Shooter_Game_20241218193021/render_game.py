def render_game(self):
        self.screen.fill((0, 0, 0))  # Clear screen with black
        self.ui_manager.display_score(self.screen)
        self.ui_manager.display_health(self.screen, self.player.health)
        pygame.display.flip()