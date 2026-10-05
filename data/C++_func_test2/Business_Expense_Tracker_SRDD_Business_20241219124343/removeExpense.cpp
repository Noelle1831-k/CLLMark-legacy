void ExpenseManager::removeExpense(int id) {
    for (size_t i = 0; i < expenses.size(); ++i) {
        if (expenses[i].getId() == id) {
            expenses.erase(expenses.begin() + i);
            cout << "Expense removed successfully.\n";
            return;
        }
    }
    cout << "Expense with ID " << id << " not found.\n";
}