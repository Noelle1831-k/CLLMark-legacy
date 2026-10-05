void BudgetManager::addIncome() {
    cout << "Enter income amount: ";
    double income;
    cin >> income;
    if (income < 0) {
        cout << "Income cannot be negative. Please try again." << endl;
        return;
    }
    totalIncome += income;
    cout << "Income added successfully." << endl;
}