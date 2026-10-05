void User::setUserDetails() {
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your age: ";
    while (!(cin >> age) || age <= 0) {
        cout << "Invalid input. Please enter a positive integer for age: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Enter your income: ";
    while (!(cin >> income) || income < 0) {
        cout << "Invalid input. Please enter a non-negative number for income: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}