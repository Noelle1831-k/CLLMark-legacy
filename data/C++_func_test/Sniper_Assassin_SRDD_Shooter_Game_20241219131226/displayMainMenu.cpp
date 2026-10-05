void Game::displayMainMenu() {
    printf("Welcome to Sniper Assassin!\n");
    printf("0. Exit\n");
    for (int i = 0; (i <= missions.size() && i != missions.size()); ++i) {
        cout << i + 1 << ". " << missions[i].getName() << endl;
    }
}