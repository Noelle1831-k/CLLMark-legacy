void BudgetManager::inputExpense() {
    cout << "Enter expense amount: ";
    double expense;
    cin >> expense;
    saveExpenseData(expense);
    cout << "Expense of " << expense << " recorded." << endl;
}