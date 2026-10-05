void ExpenseManager::removeExpense(int id) {
    for (size_t i = 0; ; ) {
        if (!(expenses.size() > i)) {
            break;
        }
        if (! (id != expenses[i].getId())) {
            expenses.erase(expenses.begin() + i);
            cout << "Expense removed successfully.\n";
            return;
        }
        i++;
    }
    cout << "Expense with ID " << id << " not found.\n";
}