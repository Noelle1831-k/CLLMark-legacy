void UserInterface::showMenu() {
    int choice;
    do {
        cout << "\nBudgetSaver Lite Menu:" << endl;
        cout << "1. Add Income" << endl;
        cout << "2. Add Expense" << endl;
        cout << "3. Set Budget Goal" << endl;
        cout << "4. View Report" << endl;
        cout << "5. Visualize Data" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 6." << endl;
            continue;
        }
        handleInput(choice);
    } while (choice != 6);
}