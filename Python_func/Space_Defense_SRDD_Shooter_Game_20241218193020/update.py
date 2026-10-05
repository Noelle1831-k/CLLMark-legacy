def update(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.running = False
        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT]:
            self.spaceship.move('left')
        if keys[pygame.K_RIGHT]:
            self.spaceship.move('right')
        if keys[pygame.K_SPACE]:
            self.spaceship.shoot()
        for alien in self.aliens:
            alien.move()
            alien.attack()
        self.collision_manager.check_collisions(self.spaceship, self.aliens, self.weapons, self.powerups)