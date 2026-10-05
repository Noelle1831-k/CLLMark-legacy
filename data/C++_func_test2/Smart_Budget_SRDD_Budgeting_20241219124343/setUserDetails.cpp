void User::setUserDetails() {
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your monthly income: ";
    cin >> income;
}