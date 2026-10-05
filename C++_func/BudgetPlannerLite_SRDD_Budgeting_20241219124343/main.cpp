int main() {
    BudgetPlanner planner;
    FileHandler fileHandler;
    int choice;
    do {
        printMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            planner.addIncome();
            break;
        case 2:
            planner.addExpense();
            break;
        case 3:
            planner.setBudgetGoal();
            break;
        case 4:
            planner.displayBudgetBreakdown();
            break;
        case 5:
            planner.viewRemainingBudget();
            break;
        case 6:
            fileHandler.saveToFile(planner);
            break;
        case 7:
            fileHandler.loadFromFile(planner);
            break;
        case 8:
            cout << "Exiting BudgetPlannerLite. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);
    return 0;
}