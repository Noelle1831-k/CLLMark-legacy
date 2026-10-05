int main() {
    cout << "=========================================" << endl;
    cout << "   Welcome to BudgetOptimizerLite Plus!   " << endl;
    cout << "=========================================" << endl;
    UserInterface ui;
    BudgetManager budgetManager;
    SavingsTracker savingsTracker;
    while (true) {
        ui.displayMainMenu();
        int choice = ui.getUserChoice();
        switch (choice) {
            case 1:
                budgetManager.addIncome();
                break;
            case 2:
                budgetManager.addExpense();
                break;
            case 3:
                savingsTracker.setSavingsGoal();
                break;
            case 4:
                savingsTracker.trackSavings();
                break;
            case 5:
                budgetManager.displayBudgetBreakdown();
                break;
            case 6:
                savingsTracker.displaySavingsSummary();
                break;
            case 0:
                cout << "Thank you for using BudgetOptimizerLite Plus!" << endl;
                cout << "Goodbye!" << endl;
                exit(0);
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
    return 0;
}