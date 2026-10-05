void Account::viewTransactions() {
    cout << "\n--- Viewing All Transactions ---" << endl;
    if (transactions.empty()) {
        cout << "No transactions available." << endl;
        return;
    }
    for (int i = 0; i < transactions.size(); i++) {
        transactions[i].printDetails();
    }
}