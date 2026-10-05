void GameManager::startGameLoop() {
    while (isGameRunning) {
        playerCivilization.displayStatus();
        cout << "Choose an action: (1) Build (2) Upgrade (3) Manage Resources (4) End Turn (5) Quit" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                playerCivilization.addStructure("Housing");
                break;
            case 2:
                playerCivilization.upgradeStructure("Housing");
                break;
            case 3:
                playerCivilization.manageResources();
                break;
            case 4:
                eventManager.triggerEvent();
                break;
            case 5:
                isGameRunning = false;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}