int main() {
    BudgetManager budgetManager;
    GamificationManager gamificationManager;
    User user;
    FileManager fileManager;
    cout << "Welcome to BudgetEnforcer!" << endl;
    fileManager.loadData(user, budgetManager);
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Set Financial Goal\n";
        cout << "2. Add Expense\n";
        cout << "3. View Remaining Budget\n";
        cout << "4. View Gamification Stats\n";
        cout << "5. View Expense Report\n";
        cout << "6. Save and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                double goal;
                cout << "Enter your financial goal: ";
                cin >> goal;
                user.setGoal(goal);
                break;
            }
            case 2: {
                double amount;
                string category;
                cout << "Enter expense amount: ";
                cin >> amount;
                cout << "Enter expense category: ";
                cin >> category;
                budgetManager.addExpense(amount, category);
                gamificationManager.awardPoints(amount);
                break;
            }
            case 3: {
                cout << "Remaining Budget: $" << budgetManager.getRemainingBudget() << endl;
                break;
            }
            case 4: {
                gamificationManager.displayAchievements();
                break;
            }
            case 5: {
                budgetManager.generateReport();
                break;
            }
            case 6: {
                fileManager.saveData(user, budgetManager);
                cout << "Data saved. Goodbye!" << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
    return 0;
}