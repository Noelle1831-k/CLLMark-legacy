def load_vehicle_images(self):
        # Load and return a list of vehicle images
        vehicle_images = []
        for i in range(5):
            image = pygame.Surface((50, 30))
            image.fill((random.randint(0, 255), random.randint(0, 255), random.randint(0, 255)))
            vehicle_images.append(image)
        return vehicle_images