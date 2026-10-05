void StockMarket::updatePrices() {
    for (auto& stock : stocks) {
        double change = (rand() % 21 - 10) / 100.0; 
        stock.updatePrice(change);
    }
}