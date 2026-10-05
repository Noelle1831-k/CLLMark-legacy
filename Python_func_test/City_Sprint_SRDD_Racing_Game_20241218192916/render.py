def render(self, car, ai_opponents, track):
        self.screen.fill((0, 0, 0))
        self.draw_car(car)
        for ai in ai_opponents:
            self.draw_car(ai)
        self.draw_track(track)
        pygame.display.flip()