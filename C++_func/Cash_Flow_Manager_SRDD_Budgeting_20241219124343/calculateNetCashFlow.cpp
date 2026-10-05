double CashFlow::calculateNetCashFlow() const {
    double netCashFlow = 0.0;
    for (int i = 0; i < transactions.size(); i++) {
        netCashFlow += transactions[i].getAmount();
    }
    return netCashFlow;
}