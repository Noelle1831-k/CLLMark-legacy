def update(self):
        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT]:
            self.position.x -= self.speed
        if keys[pygame.K_RIGHT]:
            self.position.x += self.speed
        if keys[pygame.K_UP]:
            self.position.y -= self.speed
        if keys[pygame.K_DOWN]:
            self.position.y += self.speed
        if keys[pygame.K_SPACE]:
            self.boost()