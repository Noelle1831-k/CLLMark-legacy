void Game::initialize() {
    cout << "Initializing Retail Empire..." << endl;
    store = Store();
    finance = Finance();
    customers.push_back(Customer());
    customers.push_back(Customer());
    running = true;
}