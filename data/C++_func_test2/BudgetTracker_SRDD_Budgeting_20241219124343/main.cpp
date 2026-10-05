int main() {
    BudgetTracker tracker;
    int choice;
    do {
        cout << "\nBudget Tracker Menu:" << endl;
        cout << "1. Add Income" << endl;
        cout << "2. Add Expense" << endl;
        cout << "3. View Summary" << endl;
        cout << "4. View Category Details" << endl;
        cout << "5. Save to File" << endl;
        cout << "6. Load from File" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                double income;
                cout << "Enter income amount: ";
                cin >> income;
                tracker.addIncome(income);
                break;
            }
            case 2:
                tracker.addExpense();
                break;
            case 3:
                tracker.viewSummary();
                break;
            case 4:
                tracker.viewCategoryDetails();
                break;
            case 5: {
                string filename;
                cout << "Enter filename to save: ";
                cin >> filename;
                tracker.saveToFile(filename);
                break;
            }
            case 6: {
                string filename;
                cout << "Enter filename to load: ";
                cin >> filename;
                tracker.loadFromFile(filename);
                break;
            }
            case 7:
                cout << "Exiting Budget Tracker. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);
    return 0;
}