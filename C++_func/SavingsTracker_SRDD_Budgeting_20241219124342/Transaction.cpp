Transaction::Transaction(string type, double amount, string category) {
    this->type = type;
    this->amount = amount;
    this->category = category;
    this->timestamp = time(0); 
}