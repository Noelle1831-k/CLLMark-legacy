void CashFlow::removeTransaction(int index) {
    if (index >= 0 && index < transactions.size()) {
        transactions.erase(transactions.begin() + index);
    } else {
        cout << "Invalid index!" << endl;
    }
}