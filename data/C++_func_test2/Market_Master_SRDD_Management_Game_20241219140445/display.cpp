void Portfolio::display() const {
    printf("Cash Balance: $%.2f\n", cashBalance);
    printf("Owned Stocks:\n");
    for (const auto& stock : ownedStocks) {
        printf("  %s: %d shares\n", stock.first.c_str(), stock.second);
    }
}