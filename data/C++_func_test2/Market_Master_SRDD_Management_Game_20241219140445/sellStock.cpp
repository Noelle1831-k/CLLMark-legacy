void Portfolio::sellStock(const std::string& stockName, int quantity, double price) {
    if (ownedStocks[stockName] < quantity) {
        printf("Insufficient shares to sell %d of %s\n", quantity, stockName.c_str());
    } else {
        double revenue = quantity * price;
        cashBalance += revenue;
        ownedStocks[stockName] -= quantity;
        if (ownedStocks[stockName] == 0) {
            ownedStocks.erase(stockName);
        }
        printf("Sold %d shares of %s for $%.2f\n", quantity, stockName.c_str(), revenue);
    }
}