def draw_game_scene(self, game_engine):
        self.screen.fill((0, 0, 0))
        self.draw_track(game_engine.track.layout)
        self.draw_car(game_engine.active_car)
        pygame.display.flip()