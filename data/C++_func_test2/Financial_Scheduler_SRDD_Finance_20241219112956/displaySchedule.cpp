void Schedule::displaySchedule() const {
    if (transactions.empty()) {
        cout << "No transactions scheduled." << endl;
        return;
    }
    cout << "Scheduled Transactions: " << endl;
    for (int i = 0; i < transactions.size(); ++i) {
        cout << i + 1 << ". ";
        transactions[i].displayTransaction();
    }
}