void Notification::sendNotifications(const Schedule &schedule) const {
    vector<FinancialTransaction> transactions = schedule.getTransactions();
    if (transactions.empty()) {
        cout << "No transactions to notify." << endl;
        return;
    }
    cout << "Sending notifications for upcoming transactions:" << endl;
    for (int i = 0; i < transactions.size(); ++i) {
        cout << "Reminder for Transaction " << i + 1 << ": ";
        transactions[i].displayTransaction();
    }
}