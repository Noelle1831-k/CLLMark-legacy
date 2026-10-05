double SavingsGoal::calculateTotalSavings() {
    double total = 0;
    for (int i = 0; i < transactions.size(); i++) {
        if (transactions[i].getType() == "income") {
            total += transactions[i].getAmount();
        } else {
            total -= transactions[i].getAmount();
        }
    }
    return total;
}