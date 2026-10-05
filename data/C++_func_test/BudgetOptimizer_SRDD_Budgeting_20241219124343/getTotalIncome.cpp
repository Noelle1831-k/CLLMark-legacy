double IncomeTracker::getTotalIncome() {
    double total = 0;
    for (size_t i = 0; i < incomes.size(); i++) {
        total += incomes[i].first;
    }
    return total;
}