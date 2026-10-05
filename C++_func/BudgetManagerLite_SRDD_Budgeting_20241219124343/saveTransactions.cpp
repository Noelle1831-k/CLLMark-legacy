void BudgetManager::saveTransactions(const string& filename) const {
    ofstream file(filename);
    if (file.is_open()) {
        transactionHistory.saveToFile(file);
        file.close();
        cout << "Transactions saved successfully!" << endl;
    } else {
        cout << "Error saving transactions!" << endl;
    }
}