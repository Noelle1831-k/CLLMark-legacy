void Game::simulateCustomerInteractions() {
    for (size_t i = 0; i < customers.size(); i++) {
        customers[i].interactWithStore();
    }
}