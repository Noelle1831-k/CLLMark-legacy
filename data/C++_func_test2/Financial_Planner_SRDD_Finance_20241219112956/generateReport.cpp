void User::generateReport() {
    cout << "Income Report:" << endl;
    for (double inc : income) {
        cout << inc << endl;
    }
    cout << "Expense Report:" << endl;
    for (double exp : expenses) {
        cout << exp << endl;
    }
    cout << "Savings Report:" << endl;
    for (double sav : savings) {
        cout << sav << endl;
    }
}