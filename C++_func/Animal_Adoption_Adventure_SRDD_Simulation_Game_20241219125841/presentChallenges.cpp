void Game::presentChallenges() {
    int option;
    do {
        gameMenu();
        cin >> option;
        handleOption(option);
    } while (option != 7);
}