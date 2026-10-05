void startGame(Game *game) {
    char input;
    while (game->isRunning) {
        printf("\nScore: %d\n", game->score);
        printf("Move the aircraft. Press 'Q' to quit.\n");
        input = getchar();
        if (input == 'Q' || input == 'q') {
            game->isRunning = 0;
            break;
        }
        updateGame(game, input);
        renderGame(game);
    }
}