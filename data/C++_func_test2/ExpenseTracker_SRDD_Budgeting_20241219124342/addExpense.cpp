void ExpenseManager::addExpense() {
    string desc;
    double amt;
    cout << "Enter description: ";
    cin.ignore();
    getline(cin, desc);
    cout << "Enter amount: ";
    cin >> amt;
    Expense exp;
    exp.setDetails(desc, amt);
    expenses.push_back(exp);
}