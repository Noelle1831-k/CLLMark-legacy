map<string, double> ExpenseManager::calculateCategoryTotals() const {
    map<string, double> categoryTotals;
    for (unsigned int i = 0; i < expenses.size(); i++) {
        categoryTotals[expenses[i].getCategory()] += expenses[i].getAmount();
    }
    return categoryTotals;
}