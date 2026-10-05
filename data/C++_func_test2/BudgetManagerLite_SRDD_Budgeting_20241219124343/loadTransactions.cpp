void BudgetManager::loadTransactions(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        transactionHistory.loadFromFile(file);
        file.close();
        cout << "Transactions loaded successfully!" << endl;
    } else {
        cout << "No previous transaction history found." << endl;
    }
}