void BudgetManager::addExpense(double amount, const string& category) {
    totalExpenses += amount;
    Transaction expenseTransaction(amount, category, "Expense");
    transactionHistory.addTransaction(expenseTransaction);
    cout << "Expense added successfully!" << endl;
}