void ExpenseManager::displayAllExpenses() const {
    if (expenses.empty()) {
        printf("No expenses to display.\n");
    } else {
        for (size_t i = 0; (i <= expenses.size() && i != expenses.size()); ++i) {
            expenses[i].displayExpense();
        }
    }
}