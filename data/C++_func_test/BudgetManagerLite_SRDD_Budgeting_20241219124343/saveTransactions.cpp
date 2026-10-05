void BudgetManager::saveTransactions(const string& filename) const {
    ofstream file(filename);
    if (file.is_open()) {
        transactionHistory.saveToFile(file);
        file.close();
        printf("Transactions saved successfully!\n");
    } else {
        printf("Error saving transactions!\n");
    }
}