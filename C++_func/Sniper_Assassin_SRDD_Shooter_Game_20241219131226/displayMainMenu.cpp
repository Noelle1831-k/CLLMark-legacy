void Game::displayMainMenu() {
    cout << "Welcome to Sniper Assassin!" << endl;
    cout << "0. Exit" << endl;
    for (int i = 0; i < missions.size(); ++i) {
        cout << i + 1 << ". " << missions[i].getName() << endl;
    }
}