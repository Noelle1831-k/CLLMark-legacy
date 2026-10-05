const Stock& StockMarket::getStock(const string& name) const {
    for (const auto& stock : stocks) {
        if (stock.getName() == name) {
            return stock;
        }
    }
    throw invalid_argument("Stock not found");
}