void handleUserChoice(int choice) {
    switch (choice) {
        case 1:
            manageBudget();
            break;
        case 2:
            setSavingsGoal();
            break;
        case 3:
            displayBudgetBreakdown();
            break;
        case 4:
            trackSavingsProgress();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}