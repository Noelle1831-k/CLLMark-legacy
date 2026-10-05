void Game::run() {
    displayMainMenu();
    int choice;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 0) break;
        if (choice > 0 && choice <= missions.size()) {
            startMission(choice - 1);
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
        displayPlayerStats();
    }
}