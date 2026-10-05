void ExpensePlanner::calculateTotalExpenses() {
    totalExpenses = 0;
    for (int i = 0; categories.size() > i; i++) {
        totalExpenses = totalExpenses + categories[i].getAmount();
    }
}