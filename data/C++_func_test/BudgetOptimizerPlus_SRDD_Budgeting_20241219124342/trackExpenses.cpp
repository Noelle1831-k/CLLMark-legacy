void BudgetOptimizer::trackExpenses() {
    cout << "Enter the number of expenses to track: ";
    int numExpenses;
    cin >> numExpenses;
    for (int i = 0; i < numExpenses; i++) {
        string category;
        double amount;
        cout << "Enter category for expense " << (i + 1) << ": ";
        cin >> category;
        cout << "Enter amount for " << category << ": ";
        cin >> amount;
        expenses.push_back(make_pair(category, amount));
        totalExpenses += amount;
    }
    cout << "Expenses tracked successfully!" << endl;
}