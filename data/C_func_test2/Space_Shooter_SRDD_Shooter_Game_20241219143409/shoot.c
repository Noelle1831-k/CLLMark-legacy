void shoot() {
    printf("Spaceship shooting from position (%d, %d).\n", spaceship.x, spaceship.y);
    createBullet(spaceship.x, spaceship.y);
}