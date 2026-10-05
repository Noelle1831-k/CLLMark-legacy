void moveSpaceship(Spaceship *ship, int direction) {
    int newPosition = ship->position + direction * ship->speed;
    if (newPosition >= 0 && newPosition <= SCREEN_WIDTH) {
        ship->position = newPosition;
    }
}