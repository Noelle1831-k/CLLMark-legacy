int UserInterface::displayMenu() {
    cout << "Welcome to Interactive Math Fun!" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    return choice;
}