def load_obstacle_images(self):
        # Load and return a list of obstacle images
        obstacle_images = []
        for i in range(10):
            image = pygame.Surface((20, 20))
            image.fill((random.randint(0, 255), random.randint(0, 255), random.randint(0, 255)))
            obstacle_images.append(image)
        return obstacle_images