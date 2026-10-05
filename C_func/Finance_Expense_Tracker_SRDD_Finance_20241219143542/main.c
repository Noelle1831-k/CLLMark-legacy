int main() {
    int choice;
    initialize_expenses();
    initialize_budgets();
    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                list_expenses();
                break;
            case 3:
                set_budget();
                break;
            case 4:
                display_budget_report();
                break;
            case 5:
                generate_pie_chart();
                generate_bar_chart();
                break;
            case 6:
                set_reminder();
                break;
            case 7:
                printf("Exiting the application. Goodbye!\n");
                cleanup_expenses();
                cleanup_budgets();
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}