void TransactionHistory::displayTransactions() const {
    cout << "\n=== Transaction History ===" << endl;
    for (size_t i = 0; i < transactions.size(); ++i) {
        cout << (i + 1) << ". " << transactions[i].getDetails() << endl;
    }
}