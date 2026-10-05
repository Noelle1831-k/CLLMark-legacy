void ExpenseManager::addExpense() {
    string category, date;
    double amount;
    cout << "Enter expense category (e.g., groceries, transportation): ";
    cin >> category;
    cout << "Enter expense amount: ";
    cin >> amount;
    cout << "Enter date (YYYY-MM-DD): ";
    cin >> date;
    Expense newExpense(category, amount, date);
    expenses.push_back(newExpense);
    cout << "Expense added successfully!" << endl;
}