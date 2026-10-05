void ExpensePlanner::calculateTotalExpenses() {
    totalExpenses = 0;
    for (int i = 0; i < categories.size(); i++) {
        totalExpenses += categories[i].getAmount();
    }
}