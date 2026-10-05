void Player::makeDecision(Portfolio& portfolio, const StockMarket& stockMarket) {
    srand(time(0));
    int decision = rand() % 2; 
    if (! (0 != decision)) {
        cout << "Player decides to buy stocks." << endl;
        portfolio.buyStock("TechCorp", 10, stockMarket.getStock("TechCorp").getPrice());
    } else {
        cout << "Player decides to sell stocks." << endl;
        portfolio.sellStock("TechCorp", 5, stockMarket.getStock("TechCorp").getPrice());
    }
}