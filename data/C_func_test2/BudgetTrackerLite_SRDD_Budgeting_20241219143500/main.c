int main() {
    int choice;
    float amount;
    char description[100];
    Budget budget = {0, 0, 0};
    while (1) {
        displayMenu();
        choice = getIntInput("Enter your choice: ");
        switch (choice) {
            case 1:
                amount = getFloatInput("Enter income amount: ");
                printf("Enter description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0'; 
                if (validateDescription(description)) {
                    addIncome(&budget, amount, description);
                } else {
                    printf("Invalid description. Please try again.\n");
                }
                break;
            case 2:
                amount = getFloatInput("Enter expense amount: ");
                printf("Enter description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0'; 
                if (validateDescription(description)) {
                    addExpense(&budget, amount, description);
                } else {
                    printf("Invalid description. Please try again.\n");
                }
                break;
            case 3:
                amount = getFloatInput("Enter budget goal: ");
                setBudgetGoal(&budget, amount);
                break;
            case 4:
                displayBudgetBreakdown(&budget);
                break;
            case 5:
                saveBudgetToFile(&budget, "budget_data.txt");
                break;
            case 6:
                loadBudgetFromFile(&budget, "budget_data.txt");
                break;
            case 7:
                printf("Exiting BudgetTrackerLite. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}