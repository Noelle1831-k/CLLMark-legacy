double ExpenseManager::getTotalExpenses() const {
    double total = 0.0;
    for (size_t i = 0; i < expenses.size(); i++) {
        total += expenses[i].getAmount();
    }
    return total;
}