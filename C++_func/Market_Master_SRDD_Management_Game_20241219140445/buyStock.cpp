void Portfolio::buyStock(const std::string& stockName, int quantity, double price) {
    double cost = quantity * price;
    if (!hasSufficientFunds(cost)) {
        printf("Insufficient funds to buy %d shares of %s\n", quantity, stockName.c_str());
    } else {
        cashBalance -= cost;
        ownedStocks[stockName] += quantity;
        printf("Bought %d shares of %s for $%.2f\n", quantity, stockName.c_str(), cost);
    }
}