void ReceiptScanner::scanReceipt(const string& receiptData, ExpenseManager& expenseManager) {
    istringstream stream(receiptData);
    string line;
    while (getline(stream, line)) {
        istringstream lineStream(line);
        string category, amountStr, date;
        getline(lineStream, category, ',');
        getline(lineStream, amountStr, ',');
        getline(lineStream, date, ',');
        double amount = atof(amountStr.c_str());
        expenseManager.addExpense(Expense(amount, category, date));
        cout << "Added expense from receipt: " << category << ", " << amount << ", " << date << endl;
    }
}