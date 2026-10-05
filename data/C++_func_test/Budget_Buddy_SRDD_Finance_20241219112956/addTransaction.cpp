void Account::addTransaction() {
    Transaction transaction;
    transaction.inputDetails();
    transactions.push_back(transaction);
    cout << "Transaction added successfully!" << endl;
}