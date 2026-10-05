void displayMenu() {
        cout << "Welcome to Play Learn, " << player.getName() << "!" << endl;
        cout << "Choose a game to play:" << endl;
        for (int i = 0; i < games.size(); ++i) {
            cout << i + 1 << ". " << games[i]->getGameName() << endl;
        }
        cout << "5. Check Progress" << endl;
        cout << "6. Exit" << endl;
    }