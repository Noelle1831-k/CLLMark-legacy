void ExpenseManager::removeExpense() {
    int index;
    cout << "Enter index of expense to remove: ";
    cin >> index;
    if (index >= 0 && index < expenses.size()) {
        expenses.erase(expenses.begin() + index);
    } else {
        cout << "Invalid index.\n";
    }
}