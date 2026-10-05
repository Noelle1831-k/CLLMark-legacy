void Transaction::displayTransactions() {
    cout << "\nTransactions:\n";
    for (size_t i = 0; i < transactions.size(); i++) {
        cout << i + 1 << ". " << transactions[i].first << ": $" << transactions[i].second << "\n";
    }
}