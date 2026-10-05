def render_obstacle(self, obstacle):
        # Render the obstacle on the screen at its current position
        obstacle_image = self.obstacle_images[0]  # Assuming a single image for simplicity
        self.screen.blit(obstacle_image, obstacle.position)