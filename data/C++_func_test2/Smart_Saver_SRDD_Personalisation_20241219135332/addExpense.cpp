void ExpenseManager::addExpense() {
    double amount;
    string category, date;
    cout << "Enter the expense details below." << endl;
    cout << "Amount: ";
    cin >> amount;
    cout << "Category: ";
    cin.ignore(); 
    getline(cin, category);
    cout << "Date (YYYY-MM-DD): ";
    getline(cin, date);
    expenses.push_back(Expense(amount, category, date));
    cout << "Expense added successfully!" << endl;
}