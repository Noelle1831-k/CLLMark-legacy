void BudgetManager::addTransaction(const Transaction& transaction) {
    transactions.push_back(transaction);
    totalExpenses += transaction.getAmount();
    cout << "Transaction added successfully!" << endl;
}