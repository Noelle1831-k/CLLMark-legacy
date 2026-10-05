void handleInput(Game *game) {
    char input;
    printf("Enter command (q to quit, s to shoot): ");
    scanf(" %c", &input);
    if (input == 'q') {
        game->isRunning = 0;
    } else if (input == 's') {
        shootTarget();
    }
}