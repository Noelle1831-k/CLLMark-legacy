void Transaction::displayTransaction() const {
    cout << left << setw(15) << date << setw(10) << amount << setw(30) << description << setw(20) << category << endl;
}