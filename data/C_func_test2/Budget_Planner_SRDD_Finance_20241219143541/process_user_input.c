void process_user_input() {
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            input_budget_details();
            break;
        case 2:
            generate_budget_recommendations();
            break;
        case 3:
            update_spending();
            break;
        case 4:
            show_visualization();
            break;
        case 5:
            show_spending_log();
            break;
        case 6:
            printf("Exiting the Budget Planner. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid option. Please try again.\n");
    }
}