void BudgetManager::addIncome(double amount, const string& source) {
    totalIncome += amount;
    Transaction incomeTransaction(amount, source, "Income");
    transactionHistory.addTransaction(incomeTransaction);
    cout << "Income added successfully!" << endl;
}