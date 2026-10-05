void Game::initialize() {
    printf("Initializing Retail Empire...\n");
    store = Store();
    finance = Finance();
    customers.push_back(Customer());
    customers.push_back(Customer());
    running = true;
}