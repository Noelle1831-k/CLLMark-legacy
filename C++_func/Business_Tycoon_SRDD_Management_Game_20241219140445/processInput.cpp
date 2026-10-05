void Game::processInput(int choice) {
    switch (choice) {
    case 1:
        business.displayStatus();
        break;
    case 2:
        business.expandBusiness();
        break;
    case 3:
        business.manageEmployees();
        break;
    case 4:
        business.manageInventory();
        break;
    case 5:
        business.handleFinances();
        break;
    case 6:
        business.startMarketingCampaign();
        break;
    case 7:
        saveGame();
        break;
    case 8:
        loadGame();
        break;
    case 9:
        isRunning = false;
        cout << "Exiting game. Goodbye!" << endl;
        break;
    default:
        cout << "Invalid choice. Try again." << endl;
    }
}