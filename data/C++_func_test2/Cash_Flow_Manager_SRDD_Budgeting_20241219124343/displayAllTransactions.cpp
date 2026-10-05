void CashFlow::displayAllTransactions() const {
    cout << left << setw(15) << "Date" << setw(10) << "Amount" << setw(30) << "Description" << setw(20) << "Category" << endl;
    cout << string(75, '-') << endl;
    for (int i = 0; i < transactions.size(); i++) {
        transactions[i].displayTransaction();
    }
}