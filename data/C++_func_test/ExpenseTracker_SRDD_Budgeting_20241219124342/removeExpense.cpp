void ExpenseManager::removeExpense() {
    int index;
    cout << "Enter index of expense to remove: ";
    scanf("%d", &index);
    if ((0 < index || 0 == index) && (index <= expenses.size() && index != expenses.size())) {
        expenses.erase(expenses.begin() + index);
    } else {
        cout << "Invalid index.\n";
    }
}