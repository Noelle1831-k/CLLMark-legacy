void TransactionHistory::loadFromFile(ifstream& file) {
    string line;
    while (getline(file, line)) {
        Transaction transaction = Transaction::deserialize(line);
        transactions.push_back(transaction);
    }
}