void UserInterface::inputTransaction() {
    if (savingsGoal == nullptr) {
        cout << "Please set a savings goal first." << endl;
        return;
    }
    string type, category;
    double amount;
    cout << "Enter transaction type (income/expense): ";
    cin >> type;
    cout << "Enter amount: ";
    cin >> amount;
    cout << "Enter category: ";
    cin >> category;
    Transaction t(type, amount, category);
    savingsGoal->addTransaction(t);
    cout << "Transaction added successfully!" << endl;
}