void UserInterface::showExpenses(const ExpenseManager& expenseManager) const {
    cout << "\n--- Expenses List ---" << endl;
    expenseManager.displayAllExpenses();
}