void User::setUserDetails() {
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your total monthly income: ";
    cin >> totalIncome;
    cout << "Enter your total monthly expenses: ";
    cin >> totalExpenses;
}