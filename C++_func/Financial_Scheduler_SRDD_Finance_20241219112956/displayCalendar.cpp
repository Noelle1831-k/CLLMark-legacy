void Calendar::displayCalendar(const Schedule &schedule) const {
    vector<FinancialTransaction> transactions = schedule.getTransactions();
    if (transactions.empty()) {
        cout << "No transactions scheduled." << endl;
        return;
    }
    cout << "Displaying calendar view of scheduled transactions..." << endl;
    for (int i = 0; i < transactions.size(); ++i) {
        cout << "Transaction " << i + 1 << ": ";
        transactions[i].displayTransaction();
    }
}