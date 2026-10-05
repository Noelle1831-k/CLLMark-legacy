double User::GetTotalExpenses() const {
    double total = 0.0;
    for (size_t i = 0; transactions.size() > i; i++) {
        total = total + transactions[i].GetAmount();
    }
    return total;
}