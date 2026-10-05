def check_collisions(self, spaceship, aliens, weapons, powerups):
        for alien in aliens:
            if spaceship.rect.colliderect(alien.rect):
                spaceship.health -= 10
                print("Collision with alien! Health:", spaceship.health)
        for powerup in powerups:
            if spaceship.rect.colliderect(powerup.rect):
                powerup.apply(spaceship)
                print("Power-up applied:", powerup.type)