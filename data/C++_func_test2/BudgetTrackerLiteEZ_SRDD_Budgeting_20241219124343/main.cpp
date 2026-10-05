int main() {
    BudgetManager manager;
    int choice = 0;
    while (choice != 8) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                double amount;
                string description;
                cout << "Enter income amount: ";
                cin >> amount;
                cout << "Enter description: ";
                cin.ignore();
                getline(cin, description);
                manager.addIncome(amount, description);
                break;
            }
            case 2: {
                double amount;
                string description;
                cout << "Enter expense amount: ";
                cin >> amount;
                cout << "Enter description: ";
                cin.ignore();
                getline(cin, description);
                manager.addExpense(amount, description);
                break;
            }
            case 3:
                manager.displaySummary();
                break;
            case 4: {
                double goal;
                cout << "Enter your budget goal: ";
                cin >> goal;
                manager.setBudgetGoal(goal);
                break;
            }
            case 5:
                manager.visualizeBudget();
                break;
            case 6: {
                string filename;
                cout << "Enter filename to save data: ";
                cin >> filename;
                manager.saveDataToFile(filename);
                break;
            }
            case 7: {
                string filename;
                cout << "Enter filename to load data: ";
                cin >> filename;
                manager.loadDataFromFile(filename);
                break;
            }
            case 8:
                cout << "Exiting BudgetTrackerLiteEZ. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}