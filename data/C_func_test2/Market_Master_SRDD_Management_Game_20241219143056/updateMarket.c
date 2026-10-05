void updateMarket(Market *market) {
    for (int i = 0; i < market->stockCount; i++) {
        double change = generateRandomDouble(-10.0, 10.0); 
        market->stocks[i].price += change;
        if (market->stocks[i].price < 1.0) {
            market->stocks[i].price = 1.0; 
        }
    }
}