void Game::update() {
    cout << "Updating game state..." << endl;
    store.manageInventory();
    finance.calculateProfits();
    simulateCustomerInteractions();
}