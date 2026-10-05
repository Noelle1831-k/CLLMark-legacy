void manageBudget() {
    int choice;
    printf("1. Set Budget\n");
    printf("2. View Budget\n");
    printf("3. Back to Main Menu\n");
    choice = getValidatedInput();
    switch (choice) {
        case 1:
            setBudget();
            break;
        case 2:
            printf("Current budget: %.2f\n", budget);
            break;
        case 3:
            return;
        default:
            printf("Invalid choice.\n");
    }
}