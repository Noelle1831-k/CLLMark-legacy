bool Portfolio::hasSufficientFunds(double cost) const {
    return cashBalance >= cost;
}