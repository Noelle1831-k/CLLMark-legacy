def update(self):
        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT]:
            self.position.x -= 5
        if keys[pygame.K_RIGHT]:
            self.position.x += 5
        if keys[pygame.K_UP]:
            self.position.y -= 5
        if keys[pygame.K_DOWN]:
            self.position.y += 5