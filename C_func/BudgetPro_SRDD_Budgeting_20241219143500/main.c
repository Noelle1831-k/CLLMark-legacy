int main() {
    int choice;
    char username[50];
    printf("Welcome to BudgetPro - Manage Your Finances Effectively!\n");
    printf("Enter your username: ");
    scanf("%s", username);
    if (!load_user_data(username)) {
        printf("New user detected. Initializing profile...\n");
        initialize_user(username);
    }
    while (1) {
        printf("\n--- BudgetPro Menu ---\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Set Budget Goal\n");
        printf("4. View Expense Breakdown\n");
        printf("5. Get Recommendations\n");
        printf("6. Export Data to File\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_income();
                break;
            case 2:
                add_expense();
                break;
            case 3:
                set_budget_goal();
                break;
            case 4:
                generate_pie_chart();
                generate_bar_chart();
                break;
            case 5:
                analyze_spending();
                break;
            case 6:
                export_user_data(username);
                break;
            case 7:
                printf("Saving your data...\n");
                save_user_data(username);
                printf("Thank you for using BudgetPro! Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}