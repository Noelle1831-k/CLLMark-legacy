def check_collisions(self, spaceship, aliens, asteroids, powerups, boss):
        for alien in aliens:
            if spaceship.rect.colliderect(alien.rect):
                print("Collision with alien!")
        for asteroid in asteroids:
            if spaceship.rect.colliderect(asteroid.rect):
                print("Collision with asteroid!")
        for powerup in powerups:
            if spaceship.rect.colliderect(powerup.rect):
                print("Collected power-up!")
        if spaceship.rect.colliderect(boss.rect):
            print("Collision with boss!")