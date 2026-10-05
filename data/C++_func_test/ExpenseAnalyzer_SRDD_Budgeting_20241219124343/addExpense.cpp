void ExpenseManager::addExpense() {
    string category;
    double amount;
    cout << "Enter category: ";
    cin >> category;
    cout << "Enter amount: ";
    cin >> amount;
    if (Utils::isValidCategory(category)) {
        expenses.push_back({category, amount});
        cout << "Expense added successfully.\n";
    } else {
        cout << "Invalid category. Try again.\n";
    }
}