int main() {
    BudgetMasterApp app;
    int choice = 0;
    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail() || choice < 1 || 5 < choice) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            continue;
        }
        if (choice == 5) {
            cout << "Exiting BudgetMaster. Goodbye!" << endl;
            break;
        }
        handleUserChoice(app, choice);
    }
    return 0;
}