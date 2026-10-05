void Market::analyzeTrends() {
    int index = rand() % marketFactors.size();
    trend = marketFactors[index];
}