Spaceship* createSpaceship() {
    Spaceship* spaceship = (Spaceship*)malloc(sizeof(Spaceship));
    spaceship->x = SCREEN_WIDTH / 2;
    spaceship->y = SCREEN_HEIGHT - 50;
    spaceship->health = 100;
    spaceship->weaponLevel = 1;
    spaceship->velocity = 5;
    return spaceship;
}