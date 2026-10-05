void Transaction::listTransactions() {
    cout << "Listing transactions:" << endl;
    for (int i = 0; i < transactions.size(); i++) {
        cout << transactions[i] << endl;
    }
}