void Expense::addExpense() {
    cout << "Enter expense amount: ";
    while (!(cin >> amount) || amount <= 0) {
        cout << "Invalid input. Enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();
    cout << "Enter expense description: ";
    getline(cin, description);
    categorizeExpense();
}