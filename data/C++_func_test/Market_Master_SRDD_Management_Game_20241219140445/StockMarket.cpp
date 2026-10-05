StockMarket::StockMarket() {
    stocks.push_back(Stock("TechCorp", 100.0));
    stocks.push_back(Stock("HealthInc", 150.0));
    stocks.push_back(Stock("EcoEnergy", 200.0));
    srand(time(0));
}