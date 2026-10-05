int BudgetManager::generateTransactionID() const {
    return transactions.size() + 1;
}