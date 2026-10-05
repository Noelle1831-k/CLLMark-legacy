void FinancialTransaction::displayTransaction() const {
    cout << "Amount: " << amount << ", Type: " << type
         << ", Description: " << description << ", Date: " << date << endl;
}