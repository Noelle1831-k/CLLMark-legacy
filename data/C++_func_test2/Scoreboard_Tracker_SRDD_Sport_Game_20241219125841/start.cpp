void UserInterface::start() {
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                handleAddGame();
                break;
            case 2:
                handleUpdateGame();
                break;
            case 3:
                handleDisplayGames();
                break;
            case 4:
                handleDeactivateGame();
                break;
            case 5:
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}