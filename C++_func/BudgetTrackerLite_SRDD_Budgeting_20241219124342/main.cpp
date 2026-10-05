int main() {
    BudgetTracker tracker;
    Visualizer visualizer;
    InputHandler inputHandler;
    cout << "Welcome to BudgetTrackerLite!" << endl;
    while (true) {
        displayMenu();
        int choice;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 6." << endl;
            continue;
        }
        switch (choice) {
            case 1: {
                double income = inputHandler.getDoubleInput("Enter income amount: ");
                tracker.addIncome(income);
                break;
            }
            case 2: {
                string category = inputHandler.getStringInput("Enter expense category: ");
                double amount = inputHandler.getDoubleInput("Enter expense amount: ");
                tracker.addExpense(category, amount);
                break;
            }
            case 3: {
                double goal = inputHandler.getDoubleInput("Enter your budget goal: ");
                tracker.setBudgetGoal(goal);
                break;
            }
            case 4: {
                tracker.generateReport();
                visualizer.displayPieChart(tracker.getExpenses(), tracker.getIncome());
                visualizer.displayBarChart(tracker.getExpenses());
                break;
            }
            case 5: {
                tracker.resetData();
                cout << "Budget data has been reset successfully!" << endl;
                break;
            }
            case 6: {
                cout << "Exiting BudgetTrackerLite. Goodbye!" << endl;
                return 0;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}