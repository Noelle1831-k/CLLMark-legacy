void UserInterface::displayMenu() {
    int choice;
    do {
        cout << "BudgetPlannerLite Plus Menu:" << endl;
        cout << "1. Add Income" << endl;
        cout << "2. Add Expense" << endl;
        cout << "3. Set Budget Goal" << endl;
        cout << "4. Check Budget Goal" << endl;
        cout << "5. Set Savings Goal" << endl;
        cout << "6. Add Savings" << endl;
        cout << "7. Display Budget Breakdown" << endl;
        cout << "8. Display Savings Progress" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 9." << endl;
            continue;
        }
        handleUserInput(choice);
    } while (choice != 9);
}