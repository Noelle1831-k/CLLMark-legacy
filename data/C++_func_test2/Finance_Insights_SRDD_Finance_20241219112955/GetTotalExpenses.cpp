double User::GetTotalExpenses() const {
    double total = 0.0;
    for (size_t i = 0; i < transactions.size(); i++) {
        total += transactions[i].GetAmount();
    }
    return total;
}