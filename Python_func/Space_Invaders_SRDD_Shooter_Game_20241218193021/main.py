def main():
    clock = pygame.time.Clock()
    running = True
    # Initialize game objects
    player = Player(screen)
    aliens = [Alien(screen) for _ in range(5)]
    projectiles = []
    powerups = []
    score = 0
    level = 1
    while running:
        # Event handling
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
        # Player input
        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT]:
            player.move(-1)
        if keys[pygame.K_RIGHT]:
            player.move(1)
        if keys[pygame.K_SPACE]:
            projectiles.append(player.shoot())
        # Game logic
        player.update()
        for alien in aliens:
            alien.update()
            if alien.shoot():
                projectiles.append(alien.shoot())
        for projectile in projectiles:
            projectile.move()
            if detect_collision(projectile, player):
                running = False
            for alien in aliens:
                if detect_collision(projectile, alien):
                    aliens.remove(alien)
                    score += 10
        # Check for level progression
        if not aliens:
            level += 1
            aliens = [Alien(screen) for _ in range(5 + level)]
            scale_difficulty(level)
        # Rendering
        screen.fill((0, 0, 0))
        player.draw()
        for alien in aliens:
            alien.draw()
        for projectile in projectiles:
            projectile.draw()
        pygame.display.flip()
        # Cap the frame rate
        clock.tick(FPS)