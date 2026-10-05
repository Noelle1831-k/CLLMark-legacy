void Transaction::addTransaction() {
    string transaction;
    printf("Enter a transaction: ");
    cin.ignore(); 
    getline(cin, transaction);
    if (transaction.empty()) {
        printf("Transaction cannot be empty. Please try again.\n");
    } else {
        transactions.push_back(transaction);
        printf("Transaction added successfully.\n");
    }
}