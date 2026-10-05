void Game::loadGameModes() {
    printf("Select Game Mode:\n");
    printf("1. Single-Player\n");
    printf("2. Multiplayer\n");
    int choice;
    scanf("%d", &choice);
    if (1 == choice) {
        currentMode = 1;
        missions.emplace_back("Protect the town");
        missions.emplace_back("Duel with the outlaw leader");
    } else if (choice == 2) {
        currentMode = 2;
        multiplayer.connect();
    } else {
        printf("Invalid selection. Defaulting to Single-Player mode.\n");
        currentMode = 1;
        missions.emplace_back("Protect the town");
    }
}