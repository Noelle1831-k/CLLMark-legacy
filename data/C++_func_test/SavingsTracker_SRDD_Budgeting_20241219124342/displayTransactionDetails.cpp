void Transaction::displayTransactionDetails() {
    cout << fixed << setprecision(2);
    printf("Transaction Details: \n");
    cout << "Type: " << type << endl;
    cout << "Amount: $" << amount << endl;
    cout << "Category: " << category << endl;
    cout << "Timestamp: " << getTimestamp() << endl;
}