void moveSpaceship(int dx, int dy) {
    spaceship.x += dx;
    spaceship.y += dy;
    if (spaceship.x < 0) spaceship.x = 0;
    if (spaceship.y < 0) spaceship.y = 0;
    if (spaceship.x > SCREEN_WIDTH) spaceship.x = SCREEN_WIDTH;
    if (spaceship.y > SCREEN_HEIGHT) spaceship.y = SCREEN_HEIGHT;
}