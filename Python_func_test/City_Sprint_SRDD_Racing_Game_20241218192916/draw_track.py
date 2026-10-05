def draw_track(self, track):
        for obstacle in track.get_obstacles():
            pygame.draw.rect(self.screen, (255, 255, 255), obstacle)