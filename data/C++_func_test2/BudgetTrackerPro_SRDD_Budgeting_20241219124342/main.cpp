int main() {
    BudgetTracker budgetTracker;
    Reminder reminderManager;
    Visualizer visualizer;
    FileManager fileManager;
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                double amount;
                string source;
                cout << "Enter income amount: ";
                cin >> amount;
                cout << "Enter income source: ";
                cin.ignore();
                getline(cin, source);
                budgetTracker.addIncome(amount, source);
                break;
            }
            case 2: {
                double amount;
                string category;
                cout << "Enter expense amount: ";
                cin >> amount;
                cout << "Enter expense category: ";
                cin.ignore();
                getline(cin, category);
                budgetTracker.addExpense(amount, category);
                break;
            }
            case 3: {
                double goal;
                cout << "Enter your budget goal: ";
                cin >> goal;
                budgetTracker.setBudgetGoal(goal);
                break;
            }
            case 4: {
                budgetTracker.generateReport();
                break;
            }
            case 5: {
                string description;
                cout << "Enter reminder description: ";
                cin.ignore();
                getline(cin, description);
                reminderManager.addReminder(description);
                break;
            }
            case 6: {
                reminderManager.viewReminders();
                break;
            }
            case 7: {
                fileManager.saveToFile(budgetTracker, reminderManager);
                break;
            }
            case 8: {
                fileManager.loadFromFile(budgetTracker, reminderManager);
                break;
            }
            case 9: {
                cout << "Exiting BudgetTrackerPro. Goodbye!" << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    } while (choice != 9);
    return 0;
}