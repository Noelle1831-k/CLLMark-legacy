int UserInterface::getUserChoice() {
    cout << "1. Generate and store password" << endl;
    cout << "2. Retrieve password" << endl;
    cout << "3. Remove password" << endl;
    cout << "4. Synchronize passwords" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    return choice;
}