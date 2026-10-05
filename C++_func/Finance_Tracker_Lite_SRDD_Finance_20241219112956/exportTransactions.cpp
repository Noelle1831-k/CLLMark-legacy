void FinanceTracker::exportTransactions() const {
    ofstream file("transactions.csv");
    if (!file.is_open()) {
        cout << "Error: Unable to create file.\n";
        return;
    }
    file << "Amount,Description,Category,Type\n";
    for (int i = 0; i < transactions.size(); i++) {
        file << transactions[i].getAmount() << ","
             << transactions[i].getDescription() << ","
             << transactions[i].getCategory() << ","
             << transactions[i].getType() << "\n";
    }
    file.close();
    cout << "Transactions exported successfully to transactions.csv\n";
}