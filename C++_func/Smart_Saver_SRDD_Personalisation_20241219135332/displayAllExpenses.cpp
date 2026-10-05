void ExpenseManager::displayAllExpenses() const {
    if (expenses.empty()) {
        cout << "No expenses to display." << endl;
    } else {
        for (size_t i = 0; i < expenses.size(); i++) {
            expenses[i].displayExpense();
        }
    }
}