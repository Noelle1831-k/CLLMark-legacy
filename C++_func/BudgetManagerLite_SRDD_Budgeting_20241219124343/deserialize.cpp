Transaction Transaction::deserialize(const string& data) {
    stringstream ss(data);
    string type, amountStr, description;
    getline(ss, type, ',');
    getline(ss, amountStr, ',');
    getline(ss, description);
    double amount = stod(amountStr);
    return Transaction(amount, description, type);
}