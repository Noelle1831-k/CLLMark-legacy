void Transaction::displayTransactionDetails() {
    cout << fixed << setprecision(2);
    cout << "Transaction Details: " << endl;
    cout << "Type: " << type << endl;
    cout << "Amount: $" << amount << endl;
    cout << "Category: " << category << endl;
    cout << "Timestamp: " << getTimestamp() << endl;
}