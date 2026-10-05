void ExpenseManager::displayAllExpenses() const {
    if (expenses.empty()) {
        cout << "No expenses recorded.\n";
        return;
    }
    cout << "\n---- All Expenses ----\n";
    for (size_t i = 0; i < expenses.size(); i++) {
        cout << "Expense " << i + 1 << ": " 
             << "$" << expenses[i].getAmount() << " - "
             << expenses[i].getCategory() << " - "
             << expenses[i].getDescription() << "\n";
    }
}