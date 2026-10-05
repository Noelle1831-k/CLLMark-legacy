def render_track(self):
        # Render the race track
        for obstacle in self.track.obstacles:
            pygame.draw.rect(self.screen, (128, 128, 128), pygame.Rect(obstacle.position[0], obstacle.position[1], 20, 20))
        for powerup in self.track.powerups:
            pygame.draw.circle(self.screen, (0, 0, 255), (powerup.position[0], powerup.position[1]), 10)