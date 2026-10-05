void Transaction::addTransaction() {
    string transaction;
    cout << "Enter a transaction: ";
    cin.ignore(); 
    getline(cin, transaction);
    if (transaction.empty()) {
        cout << "Transaction cannot be empty. Please try again." << endl;
    } else {
        transactions.push_back(transaction);
        cout << "Transaction added successfully." << endl;
    }
}