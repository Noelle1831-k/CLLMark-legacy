void BudgetManager::addExpense() {
    cout << "Enter expense amount: ";
    double expense;
    cin >> expense;
    if (expense < 0) {
        cout << "Expense cannot be negative. Please try again." << endl;
        return;
    }
    cout << "Enter expense category (e.g., Food, Rent): ";
    string category;
    cin.ignore();
    getline(cin, category);
    totalExpenses += expense;
    expenseCategories[category] += expense;
    cout << "Expense added successfully." << endl;
}