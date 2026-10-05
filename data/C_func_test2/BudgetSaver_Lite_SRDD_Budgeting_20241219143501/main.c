int main() {
    int choice;
    while (1) {
        displayMainMenu();
        choice = getValidatedInput(1, 4);
        switch (choice) {
            case 1:
                manageBudget();
                break;
            case 2:
                manageGoals();
                break;
            case 3:
                displayVisualization();
                break;
            case 4:
                printf("Exiting BudgetSaver Lite. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}