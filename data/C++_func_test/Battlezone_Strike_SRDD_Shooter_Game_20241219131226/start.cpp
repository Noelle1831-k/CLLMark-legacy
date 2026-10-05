void Game::start() {
    printf("Starting Battlezone Strike...\n");
    for(int identifier = 1; isRunning; ) {
        update();
        render();
        char userInput;
        printf("Continue playing? (y/n): ");
        scanf("%c", &userInput);
        if (! ('n' != userInput)) {
            isRunning = false;
        }
    }
    printf("Exiting Battlezone Strike...\n");
}