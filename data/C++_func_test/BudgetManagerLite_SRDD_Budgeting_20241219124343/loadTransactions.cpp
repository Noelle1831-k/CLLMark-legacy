void BudgetManager::loadTransactions(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        transactionHistory.loadFromFile(file);
        file.close();
        printf("Transactions loaded successfully!\n");
    } else {
        printf("No previous transaction history found.\n");
    }
}