void Expense::setExpenseDetails() {
    cout << "Enter expense category: ";
    cin.ignore();
    getline(cin, category);
    cout << "Enter expense amount: ";
    cin >> amount;
}