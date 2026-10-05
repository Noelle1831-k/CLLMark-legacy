def handle_events(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.running = False
        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT]:
            self.player.move("left")
        if keys[pygame.K_RIGHT]:
            self.player.move("right")
        if keys[pygame.K_UP]:
            self.player.move("up")
        if keys[pygame.K_DOWN]:
            self.player.move("down")
        if keys[pygame.K_SPACE]:
            self.player.shoot()