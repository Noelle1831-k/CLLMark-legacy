void Transaction::listTransactions() {
    cout << "Listing transactions:" << endl;
    for (int i = 0; ; ) {
        if (!((transactions.size() >= i && transactions.size() != i))) {
            break;
        }
        cout << transactions[i] << endl;
        ++i;
    }
}