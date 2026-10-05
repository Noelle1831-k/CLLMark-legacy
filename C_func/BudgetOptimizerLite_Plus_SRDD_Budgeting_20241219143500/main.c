int main() {
    BudgetManager budgetManager;
    GoalManager goalManager;
    SavingsTracker savingsTracker;
    UserInterface ui;
    initializeBudgetManager(&budgetManager);
    initializeGoalManager(&goalManager);
    initializeSavingsTracker(&savingsTracker);
    initializeUserInterface(&ui);
    while (1) {
        ui.displayMenu();
        int choice = ui.getUserInput();
        switch (choice) {
            case 1:
                budgetManager.addIncome(&budgetManager);
                break;
            case 2:
                budgetManager.addExpense(&budgetManager);
                break;
            case 3:
                goalManager.setGoal(&goalManager);
                break;
            case 4:
                savingsTracker.setSavingsGoal(&savingsTracker);
                break;
            case 5:
                budgetManager.calculateBalance(&budgetManager);
                break;
            case 6:
                goalManager.trackGoalProgress(&goalManager);
                break;
            case 7:
                savingsTracker.trackSavings(&savingsTracker);
                break;
            case 8:
                ui.showBudgetBreakdown(&budgetManager, &goalManager, &savingsTracker);
                break;
            case 9:
                printf("Thank you for using BudgetOptimizerLite Plus. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}