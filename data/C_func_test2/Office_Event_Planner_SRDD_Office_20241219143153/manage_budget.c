void manage_budget() {
    int choice;
    while (1) {
        printf("\n--- Manage Budget ---\n");
        printf("1. Set Budget\n");
        printf("2. Add Expense\n");
        printf("3. View Budget\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                set_budget();
                break;
            case 2:
                add_expense();
                break;
            case 3:
                view_budget();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}