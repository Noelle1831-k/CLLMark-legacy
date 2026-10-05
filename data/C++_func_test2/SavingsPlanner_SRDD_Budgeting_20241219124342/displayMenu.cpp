int UserInterface::displayMenu() {
    cout << "1. Input Income" << endl;
    cout << "2. Input Expense" << endl;
    cout << "3. Set Savings Target" << endl;
    cout << "4. Track Savings Progress" << endl;
    cout << "5. Generate Report" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    return choice;
}