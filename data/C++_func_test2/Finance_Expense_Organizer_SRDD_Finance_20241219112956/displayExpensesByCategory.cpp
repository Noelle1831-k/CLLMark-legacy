void ExpenseManager::displayExpensesByCategory(const string& category) const {
    bool found = false;
    cout << "\n---- Expenses in Category: " << category << " ----\n";
    for (size_t i = 0; i < expenses.size(); i++) {
        if (expenses[i].getCategory() == category) {
            cout << "Expense " << i + 1 << ": " 
                 << "$" << expenses[i].getAmount() << " - "
                 << expenses[i].getDescription() << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No expenses found in this category.\n";
    }
}