void BudgetManager::inputIncome() {
    cout << "Enter income amount: ";
    double income;
    cin >> income;
    saveIncomeData(income);
    cout << "Income of " << income << " recorded." << endl;
}