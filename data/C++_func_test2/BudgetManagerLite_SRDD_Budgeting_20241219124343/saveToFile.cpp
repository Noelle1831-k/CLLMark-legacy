void TransactionHistory::saveToFile(ofstream& file) const {
    for (size_t i = 0; i < transactions.size(); ++i) {
        file << transactions[i].serialize() << endl;
    }
}