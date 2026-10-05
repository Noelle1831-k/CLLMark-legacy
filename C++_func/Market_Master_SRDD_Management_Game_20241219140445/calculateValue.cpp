double Portfolio::calculateValue() const {
    double totalValue = cashBalance;
    for (const auto& stock : ownedStocks) {
        totalValue += stock.second * 100.0;  
    }
    return totalValue;
}