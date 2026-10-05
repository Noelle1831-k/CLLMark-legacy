void BudgetManager::addTransaction(const Transaction& transaction) {
    transactions.push_back(transaction);
    totalExpenses = totalExpenses + transaction.getAmount();
    printf("Transaction added successfully!\n");
}