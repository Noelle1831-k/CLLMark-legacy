void GameManager::handleInput() {
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            playerColony.displayStatus();
            break;
        case 2:
            playerColony.buildStructure();
            break;
        case 3:
            playerColony.manageResources();
            break;
        case 4:
            currentPlanet.generateChallenges();
            break;
        case 5:
            endGame();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}