def load_background_image(self):
        # Load and return the background image
        background = pygame.Surface(self.screen.get_size())
        background = background.convert()
        background.fill((0, 0, 0))  # Black background for space theme
        return background