void initializeGame(Game *game) {
    game->score = 0;
    game->level = 1;
    game->spaceship.position = SCREEN_WIDTH / 2;
    game->spaceship.speed = 2;
    game->spaceship.lives = 3;
    game->spaceship.doubleShot = 0;
    initializeAliens(game->aliens, MAX_ALIENS);
}